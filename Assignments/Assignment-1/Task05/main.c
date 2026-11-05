
#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

#ifdef DEBUG
    printf("DEBUG: Calculating bill for %d units\n", units);
#endif

    if (units > SLAB2_UNITS) {
        paise += (long)(units - SLAB2_UNITS) * RATE_PAISE;
#ifdef DEBUG
        printf("DEBUG: Charge above 200 units added\n");
#endif
    }

    if (units > SLAB1_UNITS) {
        int slab_units =
            (units < SLAB2_UNITS ? units : SLAB2_UNITS)
            - SLAB1_UNITS;

        paise += (long)slab_units * RATE2_PAISE;
    }

    if (units <= SLAB1_UNITS) {
        paise += (long)units * RATE1_PAISE;
    }

#ifdef DEBUG
    printf("DEBUG: Final bill = %ld paise\n", paise);
#endif

    return paise;
}

int main(void)
{
    int tests[] = {0, 100, 150, 200, 350};
    int n = sizeof tests / sizeof tests[0];

    for (int i = 0; i < n; i++) {
        long p = compute_bill(tests[i]);

        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], p / 100, p % 100);
    }

    return 0;
}
