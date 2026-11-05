#include <stdio.h>

void withdraw(int *balance, int amount) {
    if (amount <= 0) {
        printf("Invalid! Amount must be greater than zero.\n");
    } else if (amount > *balance) {
        printf("Invalid! Amount exceeds current balance of %d.\n", *balance);
    } else {
        *balance -= amount;
        printf("Withdrawn: %d | New balance: %d\n", amount, *balance);
    }
}

int main() {
    int balance, amount;
    int totalWithdrawals = 0, totalAmountWithdrawn = 0;
    int invalidCount = 0;
    int prevBalance;

    do {
        printf("Enter initial account balance (must be greater than 0): ");
        scanf("%d", &balance);
        if (balance <= 0)
            printf("Invalid! Balance must be greater than zero.\n");
    } while (balance <= 0);
    printf("Balance set to: %d\n\n", balance);

    while (balance > 0) {
        printf("Enter withdrawal amount (0 to stop): ");
        scanf("%d", &amount);

        if (amount == 0) {
            printf("Stopping session.\n");
            break;
        }

        prevBalance = balance;
        withdraw(&balance, amount);

        if (balance < prevBalance) {
            totalWithdrawals++;
            totalAmountWithdrawn += amount;
            invalidCount = 0;
        } else {
            invalidCount++;
            if (invalidCount >= 3) {
                printf("Transaction session terminated due to repeated invalid attempts.\n");
                break;
            }
        }
    }

    if (balance == 0)
        printf("Account emptied successfully.\n");

    printf("\n=== Transaction Summary ===\n");
    printf("  Successful withdrawals : %d\n", totalWithdrawals);
    printf("  Total amount withdrawn : %d\n", totalAmountWithdrawn);
    printf("  Final balance          : %d\n", balance);

    return 0;
}
