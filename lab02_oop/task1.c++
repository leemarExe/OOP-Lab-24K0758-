#include <iostream>

using namespace std;

class Wallet
{
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[100];
    int transactionCount;

public:
    Wallet(string name, double initialBalance = 0)
    {
        ownerName = name;
        totalBalance = initialBalance;
        transactionCount = 0;
        addTransaction("Wallet created with balance: $" + to_string(initialBalance));
    }

    void addTransaction(string transaction)
    {
        if (transactionCount < 100)
        {
            transactionHistory[transactionCount++] = transaction;
        }
    }

    void addMoney(double amount)
    {
        if (amount > 0)
        {
            totalBalance += amount;
            addTransaction("Added: $" + to_string(amount));
            cout << "Amount added successfully!\n";
        }
        else
        {
            cout << "Invalid amount! Please enter a positive value.\n";
        }
    }

    void spendMoney(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount! Please enter a positive value.\n";
            return;
        }
        if (amount > totalBalance)
        {
            cout << "Insufficient balance! Transaction declined.\n";
            return;
        }
        totalBalance -= amount;
        addTransaction("Spent: $" + to_string(amount));
        cout << "Transaction successful!\n";

        if (totalBalance < 10)
        {
            cout << "Warning: Low balance! Only $" << totalBalance << " left.\n";
        }
    }

    void displayHistory()
    {
        cout << "\nTransaction History for " << ownerName << ":\n";
        for (int i = 0; i < transactionCount; i++)
        {
            cout << "- " << transactionHistory[i] << endl;
        }
        cout << "Current Balance: $" << totalBalance << "\n";
    }
};

int main()
{
    string name;
    double initialBalance;

    cout << "Enter wallet owner's name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Wallet myWallet(name, initialBalance);

    int choice;
    double amount;

    do
    {
        cout << "\n--- Wallet Menu ---\n";
        cout << "1. Add Money\n";
        cout << "2. Spend Money\n";
        cout << "3. Show Transaction History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to add: ";
            cin >> amount;
            myWallet.addMoney(amount);
            break;
        case 2:
            cout << "Enter amount to spend: ";
            cin >> amount;
            myWallet.spendMoney(amount);
            break;
        case 3:
            myWallet.displayHistory();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
