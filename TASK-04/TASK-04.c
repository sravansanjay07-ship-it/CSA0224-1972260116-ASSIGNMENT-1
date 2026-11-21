#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define RUPEES_TO_PAISE(r) ((long long)(r) * 100)

int main()
{
    int a = 3, b = 7;

    printf("Square: %d\n", SQUARE(a + 1));
    printf("Maximum: %d\n", MAX(a, b));
    printf("Rupees to Paise: %lld\n", RUPEES_TO_PAISE(50));

    return 0;
}
