#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MODULUS 65536U
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL

int read_meter(const char *message, unsigned int *value)
{
    char input[100];
    char *end;
    unsigned long number;

    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) == NULL)
        return 0;

    number = strtoul(input, &end, 10);

    if (end == input || input[0] == '-' || number > 65535)
        return 0;

    while (*end == ' ' || *end == '\t' ||
           *end == '\n' || *end == '\r')
        end++;

    if (*end != '\0')
        return 0;

    *value = (unsigned int)number;
    return 1;
}

long long calculate_bill(unsigned int units)
{
    long long energy = 0;

    if (units > 200)
        energy = 100LL * RATE2 + (units - 200LL) * RATE3;
    else if (units > 100)
        energy = (units - 100LL) * RATE2;

    return FIXED + energy;
}

int main()
{
    unsigned int previous, current, units;
    int rollover;
    long long bill;

    if (!read_meter("Previous reading: ", &previous) ||
        !read_meter("Current reading: ", &current))
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Rollover confirmed? (1=yes, 0=no): ");

    if (scanf("%d", &rollover) != 1 ||
        (rollover != 0 && rollover != 1))
    {
        printf("Invalid rollover choice\n");
        return 1;
    }

    if (current >= previous)
        units = current - previous;
    else if (rollover)
        units = (MODULUS - previous) + current;
    else
    {
        printf("Invalid reading decrease\n");
        return 1;
    }

    bill = calculate_bill(units);

    printf("Units consumed: %u\n", units);
    printf("Total Bill: Rs %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
