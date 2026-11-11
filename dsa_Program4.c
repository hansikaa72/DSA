#include<stdio.h>
#include<string.h>
#define MAX 100

struct BankAccount
{
    int accountNo;
    char name[50];
    float balance;
};

void createAccounts(struct BankAccount accounts[], int *n)
{
    printf("Enter number of accounts: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        printf("\nEnter details for Account %d\n", i + 1);

        printf("Account Number: ");
        scanf("%d", &accounts[i].accountNo);

        printf("Account Holder Name: ");
        scanf(" %[^\n]", accounts[i].name);

        printf("Initial Balance: ");
        scanf("%f", &accounts[i].balance);
    }
}

void displayAccounts(struct BankAccount accounts[], int n)
{
    printf("\n----- Account Details -----\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nAccount Number : %d", accounts[i].accountNo);
        printf("\nAccount Holder : %s", accounts[i].name);
        printf("\nBalance         : %.2f\n", accounts[i].balance);
    }
}

int searchAccount(struct BankAccount accounts[], int n, int accountNo)
{
    for (int i = 0; i < n; i++)
    {
        if (accounts[i].accountNo == accountNo)
            return i;
    }

    return -1;
}

void deposit(struct BankAccount accounts[], int n)
{
    int accountNo, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = searchAccount(accounts, n, accountNo);

    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        accounts[index].balance += amount;
        printf("Amount deposited successfully.\n");
        printf("Updated Balance = %.2f\n", accounts[index].balance);
    }
    else
    {
        printf("Invalid amount.\n");
    }
}

void withdraw(struct BankAccount accounts[], int n)
{
    int accountNo, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = searchAccount(accounts, n, accountNo);

    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount.\n");
    }
    else if (amount > accounts[index].balance)
    {
        printf("Insufficient balance.\n");
    }
    else
    {
        accounts[index].balance -= amount;
        printf("Amount withdrawn successfully.\n");
        printf("Remaining Balance = %.2f\n", accounts[index].balance);
    }
}

float totalBalance(struct BankAccount accounts[], int n)
{
    float total = 0;

    for (int i = 0; i < n; i++)
    {
        total += accounts[i].balance;
    }

    return total;
}

int main()
{
    struct BankAccount accounts[MAX];
    int n = 0;
    int choice, accountNo, index;

    do
    {
        printf("\n========== BANK ACCOUNT MANAGEMENT ==========\n");
        printf("1. Create Accounts\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account\n");
        printf("6. Calculate Total Balance\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccounts(accounts, &n);
                break;

            case 2:
                displayAccounts(accounts, n);
                break;

            case 3:
                deposit(accounts, n);
                break;

            case 4:
                withdraw(accounts, n);
                break;

            case 5:
                printf("Enter account number to search: ");
                scanf("%d", &accountNo);

                index = searchAccount(accounts, n, accountNo);

                if (index != -1)
                {
                    printf("\nAccount Found!\n");
                    printf("Account Number : %d\n", accounts[index].accountNo);
                    printf("Account Holder : %s\n", accounts[index].name);
                    printf("Balance     : %.2f\n", accounts[index].balance);
                }
                else
                {
                    printf("Account not found.\n");
                }
                break;

            case 6:
                printf("Total balance of all accounts = %.2f\n",
                       totalBalance(accounts, n));
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}