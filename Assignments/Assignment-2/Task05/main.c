
#include <stdio.h>

unsigned long checks = 0;

// 1. Basic FOR loop: 2 to n-1
int prime_basic(unsigned long n)
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

// 2. Improved FOR loop: up to square root of n
int prime_for(unsigned long n)
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

// 3. Improved WHILE loop
int prime_while(unsigned long n)
{
    unsigned long i = 2;
    checks = 0;

    if (n < 2)
        return 0;

    while (i <= n / i)
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;
    }

    return 1;
}

// 4. Improved DO-WHILE loop
int prime_do_while(unsigned long n)
{
    unsigned long i = 2;
    checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    do
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;

    } while (i <= n / i);

    return 1;
}

// 5. Changed condition: i < n
int prime_linear(unsigned long n)
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

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    int k, p;

    printf("TICKET PRIME BASIC FOR WHILE DO-WHILE\n");
    printf("------------------------------------------\n");

    for (k = 0; k < 4; k++)
    {
        printf("%7lu ", tickets[k]);

        p = prime_basic(tickets[k]);
        printf("%-6s %5lu ", p ? "Prime" : "Not", checks);

        p = prime_for(tickets[k]);
        printf("%5lu ", checks);

        p = prime_while(tickets[k]);
        printf("%5lu ", checks);

        p = prime_do_while(tickets[k]);
        printf("%8lu\n", checks);
    }

    // Demonstrate changed loop condition
    printf("\n--- CONDITION i < n ---\n");

    for (k = 0; k < 4; k++)
    {
        prime_linear(tickets[k]);

        printf("%lu divisions = %lu\n",
               tickets[k], checks);
    }

    return 0;
}
