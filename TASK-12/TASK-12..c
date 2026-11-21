#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned long long watt_hours;
    unsigned long long normal_rate, peak_rate;
    unsigned long long rate, charge;
    int peak;

    printf("Enter energy in watt-hours: ");
    if (scanf("%llu", &watt_hours) != 1)
    {
        printf("Invalid energy input\n");
        return 1;
    }

    printf("Enter normal rate (paise per kWh): ");
    if (scanf("%llu", &normal_rate) != 1 ||
        normal_rate > ULLONG_MAX / 120)
    {
        printf("Invalid tariff rate\n");
        return 1;
    }

    peak_rate = (normal_rate * 120 + 50) / 100;

    printf("Peak hour? (1=Yes, 0=No): ");
    if (scanf("%d", &peak) != 1 ||
        (peak != 0 && peak != 1))
    {
        printf("Invalid choice\n");
        return 1;
    }

    rate = peak ? peak_rate : normal_rate;

    if (rate != 0 &&
        watt_hours > (ULLONG_MAX - 500) / rate)
    {
        printf("Energy value is too large\n");
        return 1;
    }

    charge = (watt_hours * rate + 500) / 1000;

    printf("\n----- SMART METER BILL -----\n");
    printf("Energy: %llu Wh\n", watt_hours);
    printf("Normal Rate: %llu paise\n", normal_rate);
    printf("Peak Rate: %llu paise\n", peak_rate);
    printf("Applied Rate: %llu paise\n", rate);
    printf("Total Charge: %llu paise\n", charge);

    printf("Bill: Rs %llu.%02llu\n",
           charge / 100, charge % 100);

    return 0;
}
