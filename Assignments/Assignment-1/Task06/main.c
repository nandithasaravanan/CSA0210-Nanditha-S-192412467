
#include <stdio.h>

int main(void)
{
    int units;
    long paise = 16250L;

    printf("Enter electricity units: ");

    if (scanf("%d", &units) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 1;
    }

    if (units < 0) {
        printf("Invalid input! Units cannot be negative.\n");
        return 1;
    }

    printf("Units consumed: %d\n", units);
    printf("Bill amount: Rs %ld.%02ld\n",
           paise / 100, paise % 100);

    return 0;
}
