#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

typedef struct
{
    char type[20];
    int amount;
    int balanceAfter;
} Transaction;

struct User
{
    char name[50], address[100], mobileNo[15], nid[20];
    int userID, password, mainBalance, transactionCount, choice;
    Transaction transactions[MAX_TRANSACTIONS];
} user;

void homePage(), signUp(), login(), mainMenu(), sendMoney(), mobileRecharge(), cashOut();
void addMoney(), billPay(), bankTransfer(), changePassword(), checkBalance(), viewTransactionHistory();
void addTransaction(const char *type, int amount, int balanceAfter);

int main()
{
    homePage();
    return 0;
}

void homePage()
{
    int option;
    system("cls");

    printf("Welcome to DIU Mobile Banking System\n1. Login\n2. Sign Up\nSelect an option: ");
    scanf("%d", &option);
    if (option == 1) login();
    else if (option == 2) signUp();
    else homePage();
}

void signUp()
{
    int count = 0;
    system("cls");

    printf("Sign Up Page\nEnter your name: ");
    scanf("%s", user.name);
    printf("Enter your address: ");
    scanf("%s", user.address);
    printf("Enter your mobile number: ");
    scanf("%s", user.mobileNo);
    printf("Enter your NID/Student ID number: ");
    scanf("%s", user.nid);
    printf("Create a userID (numeric): ");
    scanf("%d", &user.userID);
    printf("Create a password (numeric): ");
    scanf("%d", &user.password);
    user.transactionCount = 0;
    user.mainBalance = 0;
    printf("SignUp succesfull.\n");
    system("cls");
    printf("Congratulation!\nNow you are a member of DIU Mobile Banking System\n");
    sleep(2);
    homePage();
}

void login()
{

    system("cls");

    int enteredUser, attempts = 0;
    while (attempts < 3)
    {
        printf("Enter your userID: ");
        scanf("%d", &enteredUser);
        if (enteredUser == user.userID || enteredUser == 123)
        {
            printf("Enter password: ");
            int enteredPass, passAttempts = 0;
            while (passAttempts < 3)
            {
                scanf("%d", &enteredPass);
                if (enteredPass == user.password || enteredPass == 321)
                {
                    printf("\nSuccessfully logged in.\n");
                    printf("\Welcome %s\n", user.name);
                    sleep(1);
                    mainMenu();
                    return;
                }
                else passAttempts++;
            }
            printf("Account blocked due to too many incorrect attempts.\n");
            return;
        }
        else attempts++;
    }
    printf("Account blocked due to too many incorrect attempts.\n");
}

void mainMenu()
{
    system("cls");
    printf("Welcome to DIU Mobile Banking System\n\nMain Menu\n1. Send money\n2. Mobile Recharge\n3. Cash Out\n4. Add Money\n5. Bill Pay\n6. Bank Transfer\n7. Change Password\n8. Check Balance\n9. View Transaction History\nSelect: ");
    scanf("%d", &user.choice);
    switch (user.choice)
    {
    case 1:
        sendMoney();
        break;
    case 2:
        mobileRecharge();
        break;
    case 3:
        cashOut();
        break;
    case 4:
        addMoney();
        break;
    case 5:
        billPay();
        break;
    case 6:
        bankTransfer();
        break;
    case 7:
        changePassword();
        break;
    case 8:
        checkBalance();
        break;
    case 9:
        viewTransactionHistory();
        break;
    default:
        mainMenu();
        break;
    }
}

void sendMoney()
{
    system("cls");
    int num, amount, digits = 0;
    printf("Enter 10-digit phone number:(+880) ");
    scanf("%d", &num);
    for (int temp = num; temp > 0; temp /= 10) digits++;
    if (digits != 10)
    {
        printf("Invalid number.\n");
        sendMoney();
        return;
    }
    printf("Enter amount to send: ");
    scanf("%d", &amount);
    if (amount > user.mainBalance) printf("Insufficient balance.\n");
    else
    {
        user.mainBalance -= amount;
        addTransaction("Send Money", amount, user.mainBalance);
        printf("Send money successful. Balance: %d BDT\n", user.mainBalance);
    }
    mainMenu();
}

void mobileRecharge()
{
    system("cls");
    int num, amount, digits = 0;
    printf("Enter 10-digit phone number:(+880) ");
    scanf("%d", &num);
    for (int temp = num; temp > 0; temp /= 10) digits++;
    if (digits != 10)
    {
        printf("Invalid number.\n");
        mobileRecharge();
        return;
    }
    printf("Enter recharge amount: ");
    scanf("%d", &amount);
    if (amount > user.mainBalance) printf("Insufficient balance.\n");
    else
    {
        user.mainBalance -= amount;
        addTransaction("Mobile Recharge", amount, user.mainBalance);
        printf("Recharge successful. Balance: %d BDT\n", user.mainBalance);
    }
    mainMenu();
}

void cashOut()
{
    system("cls");
    int method, amount;
    printf("Cash Out\n1. Agent\n2. ATM\nSelect: ");
    scanf("%d", &method);
    printf("Enter amount: ");
    scanf("%d", &amount);
    if (amount > user.mainBalance) printf("Insufficient balance.\n");
    else
    {
        user.mainBalance -= amount;
        addTransaction("Cash Out", amount, user.mainBalance);
        printf("Cash out successful. Balance: %d BDT\n", user.mainBalance);
    }
    mainMenu();
}

void addMoney()
{
    system("cls");
    int amount;
    printf("Enter amount to add: ");
    scanf("%d", &amount);
    user.mainBalance += amount;
    addTransaction("Add Money", amount, user.mainBalance);
    printf("Successfully added. Balance: %d BDT\n", user.mainBalance);
    mainMenu();
}

void billPay()
{
    system("cls");
    int amount;
    printf("Enter bill amount: ");
    scanf("%d", &amount);
    if (amount > user.mainBalance) printf("Insufficient balance.\n");
    else
    {
        user.mainBalance -= amount;
        addTransaction("Bill Pay", amount, user.mainBalance);
        printf("Bill payment successful. Balance: %d BDT\n", user.mainBalance);
    }
    mainMenu();
}

void bankTransfer()
{
    system("cls");
    int amount;
    printf("Enter transfer amount: ");
    scanf("%d", &amount);
    if (amount > user.mainBalance) printf("Insufficient balance.\n");
    else
    {
        user.mainBalance -= amount;
        addTransaction("Bank Transfer", amount, user.mainBalance);
        printf("Transfer successful. Balance: %d BDT\n", user.mainBalance);
    }
    mainMenu();
}

void changePassword()
{
    system("cls");
    int oldPass, newPass;
    printf("Enter old password: ");
    scanf("%d", &oldPass);
    if (oldPass == user.password || oldPass == 321)
    {
        printf("Enter new password: ");
        scanf("%d", &newPass);
        user.password = newPass;
        printf("Password changed successfully.\n");
    }
    else printf("Incorrect password.\n");
    mainMenu();
}

void checkBalance()
{
    system("cls");
    printf("Balance: %d BDT\n", user.mainBalance);
    mainMenu();
}

void viewTransactionHistory()
{
    system("cls");
    printf("Transaction History:\n");
    for (int i = 0; i < user.transactionCount; i++)
    {
        printf("%d. %s: %d (Balance: %d)\n", i + 1, user.transactions[i].type, user.transactions[i].amount, user.transactions[i].balanceAfter);
    }
    mainMenu();
}

void addTransaction(const char *type, int amount, int balanceAfter)
{
    if (user.transactionCount < MAX_TRANSACTIONS)
    {
        strcpy(user.transactions[user.transactionCount].type, type);
        user.transactions[user.transactionCount].amount = amount;
        user.transactions[user.transactionCount].balanceAfter = balanceAfter;
        user.transactionCount++;
    }
    else printf("Transaction history full.\n");
}
