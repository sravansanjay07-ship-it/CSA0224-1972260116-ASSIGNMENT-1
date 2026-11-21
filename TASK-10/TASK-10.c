#include <stdio.h>

int main()
{
    int houses[] = {4000, 60000, 800000};

    long long bill_paise = 95000;
    double bill_rupees = 950.00;

    for (int i = 0; i < 3; i++)
    {
        long long total_paise = bill_paise * houses[i];
        double total_rupees = bill_rupees * houses[i];

        printf("\nHouseholds: %d\n", houses[i]);

        printf("Integer total: Rs %lld.%02lld\n",
               total_paise / 100, total_paise % 100);

        printf("Double total: Rs %.2f\n", total_rupees);
    }

    return 0;
}
