#include <stdio.h>

int main()
{
    int units;
    long long paise;

    printf("Enter units: ");

    if (scanf("%d", &units) != 1 || units < 0)
    {
        printf("Invalid units\n");
        return 1;
    }

    printf("Enter bill in paise: ");

    if (scanf("%lld", &paise) != 1 || paise < 0)
    {
        printf("Invalid amount\n");
        return 1;
    }

    printf("Bill: Rs %lld.%02lld\n",
           paise / 100, paise % 100);

    return 0;
}
