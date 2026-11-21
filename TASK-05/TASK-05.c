#include <stdio.h>

#define FIXED_CHARGE 5000LL
#define RATE2 225LL
#define RATE3 450LL

long long compute_bill(int units)
{
    long long energy = 0;

    if (units > 200)
        energy = 100LL * RATE2 + (units - 200LL) * RATE3;

    else if (units > 100)
        energy = (units - 100LL) * RATE2;

#ifdef DEBUG
    printf("Debug: Units = %d\n", units);
    printf("Debug: Energy = %lld paise\n", energy);
#endif

    return FIXED_CHARGE + energy;
}

int main()
{
    int units = 150;

    long long bill = compute_bill(units);

    printf("Units consumed: %d\n", units);
    printf("Total Bill: Rs %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
