 #include <stdio.h>

void Card();
void Pin(int bal);
void Enquiry(int bal);

int main() {
    Card();
    return 0;
}

void Card() {
    char card;
    int n, bal;

    printf("Welcome to XYZ ATM Service\n");
    printf("Please place your card here (k, i, or a): ");
    scanf(" %c", &card);

    switch (card) {
        case 'k':
            bal = 50000;
            break;
        case 'i':
            bal = 100000;
            break;
        case 'a':
            bal = 80000;
            break;
        default:
            printf("Invalid card. Exiting...\n");
            return;
    }

    printf("Press 1 to Make a Withdrawal\n");
    printf("Press 2 for Balance Enquiry\n");
    scanf("%d", &n);

    if (n == 1) {
        Pin(bal);
    } else if (n == 2) {
        Enquiry(bal);
    } else {
        printf("Invalid option selected. Exiting...\n");
    }
}

void Pin(int bal) {
    int pin, withdraw, rembal;

    printf("Please Enter Your 4-Digit Pin: ");
    scanf("%d", &pin);

    if (pin == 1234) {
        printf("Enter the amount to be Withdrawn: ");
        scanf("%d", &withdraw);

        if (withdraw > bal) {
            printf("Insufficient Balance. Available balance: %d\n", bal);
        } else {
            rembal = bal - withdraw;
            printf("Withdrawal Successful! Remaining balance: %d\n", rembal);
        }
    } else {
        printf("Incorrect Pin. Please Try Again.\n");
        Pin(bal);
    }
}

void Enquiry(int bal) {
    int pin;

    printf("Enter Your 4-Digit Pin: ");
    scanf("%d", &pin);

    if (pin == 1234) {
        printf("Your Balance is: %d\n", bal);
        printf("Thank you for visiting our ATM!\n");
    } else {
        printf("Incorrect Pin. Please Try Again.\n");
        Enquiry(bal);
    }
}
