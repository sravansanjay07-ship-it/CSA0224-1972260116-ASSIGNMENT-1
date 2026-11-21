#include <stdio.h>

int main()
{
    int household, previous, current, units;
    long long energy = 0, total;

    printf("Enter household number: ");
    scanf("%d", &household);

    printf("Enter previous reading: ");
    scanf("%d", &previous);

    printf("Enter current reading: ");
    scanf("%d", &current);

    if (previous < 0 || previous > 65535 ||
        current < previous || current > 65535)
    {
        printf("Invalid readings\n");
        return 1;
    }

    units = current - previous;

    if (units > 200)
        energy = 100LL * 225 + (units - 200LL) * 450;
    else if (units > 100)
        energy = (units - 100LL) * 225;

    total = 5000 + energy;

    printf("\nHousehold: %d\n", household);
    printf("Units: %d\n", units);
    printf("Energy Charge: Rs %lld.%02lld\n",
           energy / 100, energy % 100);
    printf("Fixed Charge: Rs 50.00\n");
    printf("Total Bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}
