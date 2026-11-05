
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int units = 199;
    long paise = 16250L;
    long large = 3000000000L;

    /* Surprise 1: Integer division */
    printf("1. 199 / 100 = %d\n", units / 100);

    /* Surprise 2: Integer division before conversion */
    printf("2. (float)(199 / 100) = %.2f\n",
           (float)(units / 100));

    /* Surprise 3: Casting a large long to int */
    printf("3. (int)3000000000L = %d\n", (int)large);

    /* Correct conversion to floating point */
    printf("4. (float)199 / 100 = %.2f\n",
           (float)units / 100);

    /* Correct rupees and paise formatting */
    printf("5. Bill = Rs %ld.%02ld\n",
           paise / 100, paise % 100);

    /* Fractional paise and rounding */
    double charge = 2.255 * 100;
    printf("6. 2.255 * 100 = %.15f\n", charge);
    printf("7. Rounded paise = %.0f\n", charge);

    return 0;
}
