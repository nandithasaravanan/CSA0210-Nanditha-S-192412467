
#include <stdio.h>

unsigned long checks = 0;

// Version 1: Original method (2 to n-1)
int prime_original(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i < n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

// Version 2: Improved method (up to square root)
int prime_sqrt(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

// Version 3: Redesigned method (6k +/- 1)
int prime_optimized(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    if (n == 2 || n == 3)
        return 1;

    // Check divisibility by 2
    checks++;

    if (n % 2 == 0)
        return 0;

    // Check divisibility by 3
    checks++;

    if (n % 3 == 0)
        return 0;

    // Check possible divisors of the form 6k +/- 1
    for (i = 5; i <= n / i; i += 6)
    {
        checks++;

        if (n % i == 0)
            return 0;

        // Check the next possible divisor
        if (i + 2 <= n / (i + 2))
        {
            checks++;

            if (n % (i + 2) == 0)
                return 0;
        }
    }

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {
        97, 100, 7919, 1000003
    };

    int i, result;

    unsigned long original_count;
    unsigned long sqrt_count;
    unsigned long optimized_count;

    printf("PRIME NUMBER PERFORMANCE COMPARISON\n");
    printf("-----------------------------------------------\n");

    printf("Ticket     Original    SquareRoot    Optimized\n");

    for (i = 0; i < 4; i++)
    {
        // Original method
        result = prime_original(tickets[i]);
        original_count = checks;

        // Square-root method
        prime_sqrt(tickets[i]);
        sqrt_count = checks;

        // Optimized 6k +/- 1 method
        prime_optimized(tickets[i]);
        optimized_count = checks;

        printf("%-10lu %-11lu %-13lu %-10lu\n",
               tickets[i],
               original_count,
               sqrt_count,
               optimized_count);
    }

    // Detailed comparison for the largest ticket
    printf("\n--- FINAL PERFORMANCE ANALYSIS ---\n");

    prime_original(1000003);
    original_count = checks;

    prime_sqrt(1000003);
    sqrt_count = checks;

    prime_optimized(1000003);
    optimized_count = checks;

    printf("Original tests   = %lu\n", original_count);
    printf("Square-root tests = %lu\n", sqrt_count);
    printf("Optimized tests  = %lu\n", optimized_count);

    printf("Tests saved compared to square-root = %lu\n",
           sqrt_count - optimized_count);

    printf("Tests saved compared to original = %lu\n",
           original_count - optimized_count);

    return 0;
}
