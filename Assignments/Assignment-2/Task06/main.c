
#include <stdio.h>

#define MAX_MONTHS 360

// Function to calculate loan repayment
int calculate_loan(double principal, double rate,
                   double repayment, int show_schedule,
                   double *total_interest)
{
    double balance = principal;
    double interest, amount_due, actual_payment;

    int month = 0;

    *total_interest = 0.0;

    // Check whether the loan can be repaid
    if (principal <= 0 || rate < 0 ||
        repayment <= principal * rate)
    {
        return -1;
    }

    while (balance > 0.0)
    {
        // Safety limit
        if (month >= MAX_MONTHS)
        {
            printf("Safety limit reached: Loan not fully repaid.\n");
            return -2;
        }

        month++;

        // Calculate monthly interest
        interest = balance * rate;

        *total_interest += interest;

        // Add interest to outstanding balance
        amount_due = balance + interest;

        // Adjust repayment in the final month
        if (amount_due <= repayment)
        {
            actual_payment = amount_due;
            balance = 0.0;
        }
        else
        {
            actual_payment = repayment;
            balance = amount_due - repayment;
        }

        // Display monthly schedule
        if (show_schedule)
        {
            printf("%5d %14.2f %12.2f %14.2f %14.2f\n",
                   month, amount_due - interest,
                   interest, actual_payment, balance);
        }

        if (balance <= 0.0)
        {
            break;
        }
    }

    return month;
}

int main(void)
{
    double principal = 10000.0;
    double rate = 0.02;
    double repayment = 2000.0;

    double total_interest;
    double interest;
    double payments[] = {2000, 500, 250, 201, 200};

    int months, i;

    printf("----- LOAN REPAYMENT SCHEDULE -----\n");

    printf("Principal = Rs. %.2f\n", principal);
    printf("Interest Rate = %.2f%%\n", rate * 100);
    printf("Monthly Repayment = Rs. %.2f\n\n", repayment);

    printf("Month   Opening Balance   Interest   Repayment   Closing Balance\n");

    months = calculate_loan(principal, rate,
                            repayment, 1,
                            &total_interest);

    if (months > 0)
    {
        printf("\nTotal Months = %d\n", months);
        printf("Total Interest = Rs. %.2f\n",
               total_interest);
    }
    else
    {
        printf("\nLoan could not be completed.\n");
    }

    // Growth investigation
    printf("\n----- GROWTH INVESTIGATION -----\n");
    printf("Repayment    Months\n");

    for (i = 0; i < 5; i++)
    {
        months = calculate_loan(principal, rate,
                                payments[i], 0,
                                &interest);

        if (months == -1)
        {
            printf("%8.2f    Cannot repay\n",
                   payments[i]);
        }
        else if (months == -2)
        {
            printf("%8.2f    Safety limit reached\n",
                   payments[i]);
        }
        else
        {
            printf("%8.2f    %d\n",
                   payments[i], months);
        }
    }

    return 0;
}
