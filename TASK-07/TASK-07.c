#include <stdio.h>

int main()
{
    printf("Integer division: %d\n", 5 / 2);

    printf("Float division: %.2f\n", (float)5 / 2);

    printf("Casting after division: %.2f\n", (float)(5 / 2));

    printf("Unsafe square result: %d\n", 3 + 1 * 3 + 1);

    printf("Correct square result: %d\n", (3 + 1) * (3 + 1));

    return 0;
}
