#include <stdlib.h>
#include <stdio.h>

// CIBC ATM Banking Application using C
// Pathum Danthanarayana

int main(void)
{

	float chequingBalance = 0.00;	// Initialize chequing balance
	float savingsBalance = 0.00;	// Initialize savings balance
	int userPin = 1234;
	int tempPin;
	int moreTransaction = 1;	// If moreTransaction is 1, this indicates the user wants to complete another transaction
	// If moreTransaction is 2, this indicates the user does not want to complete another transaction

	printf("****  WELCOME TO CIBC SECURE ATM ****\n\n");	// ATM Header

	// Check for correct pin entry

	printf("PLEASE ENTER YOUR 4-DIGIT PIN: ");
	scanf("%d", &tempPin);

	if (userPin != tempPin)
	{
		printf("INVALID PIN. PLEASE TRY AGAIN.\n");
		return 0;
	}

	while (moreTransaction == 1)
	{

		int userChoice;

		// Main Menu
		printf("\n1. CHECK BALANCE\n2. DEPOSIT FUNDS\n3. WITHDRAW FUNDS\n4. EXIT\n");
		scanf("%d", &userChoice);

		// Check balance
		if (userChoice == 1)
		{
			printf("1. CHECK BALANCE OF CHEQUING\n2. CHECK BALANCE OF SAVINGS\n");
			scanf("%d", &userChoice);

			if (userChoice == 1)
			{
				printf("$%.2f\n", chequingBalance);
			}
			else if (userChoice == 2)
			{
				printf("$%.2f\n", savingsBalance);
			}
		}

		// Deposit funds
		else if (userChoice == 2)
		{
			float depositAmount;
			printf("PLEASE ENTER THE AMOUNT OF FUNDS YOU WOULD LIKE TO DEPOSIT:\n");
			scanf("%f", &depositAmount);
			printf("WHICH ACCOUNT WOULD YOU LIKE TO DEPOSIT FUNDS INTO?\n1. CHEQUING\n2. SAVINGS\n");
			scanf("%d", &userChoice);

			if (userChoice == 1)
			{
				chequingBalance += depositAmount;
				printf("YOUR NEW BALANCE OF CHEQUING IS $%.2f\n", chequingBalance);
			}
			else if (userChoice == 2)
			{
				savingsBalance += depositAmount;
				printf("YOUR NEW BALANCE OF SAVINGS $%.2f\n", savingsBalance);
			}
		}

		// Withdraw funds
		else if (userChoice == 3)
		{
			float withdrawAmount;
			printf("PLEASE ENTER THE AMOUNT OF FUNDS YOU WOULD LIKE TO WITHDRAW:\n");
			scanf("%f", &withdrawAmount);
			printf("WHICH ACCOUNT WOULD YOU LIKE TO WITHDRAW FUNDS FROM?\n1. CHEQUING\n2. SAVINGS\n");
			scanf("%d", &userChoice);

			if (userChoice == 1)
			{
				chequingBalance -= withdrawAmount;
				printf("YOUR NEW BALANCE OF CHEQUING IS $%.2f\n", chequingBalance);
			}
			else if (userChoice == 2)
			{
				savingsBalance -= withdrawAmount;
				printf("YOUR NEW BALANCE OF SAVINGS $%.2f\n", savingsBalance);
			}
		}

		else
		{
			printf("INVALID TRANSACTION. PLEASE TRY AGAIN./n");
		}

		// Ask user if they would like to complete another transaction

		moreTransaction = 0;

		while (moreTransaction != 1 && moreTransaction != 2)
		{
			printf("WOULD YOU LIKE TO COMPLETE ANOTHER TRANSACTION?\n");
			printf("1 - YES\n2 - NO\n");
			scanf("%d", &moreTransaction);
		}
	}
	// Thank you message once the user has finished completing transactions

	printf("THANK YOU FOR USING THE CIBC SECURE ATM. HAVE A NICE DAY!\n");
	return 0;
}
