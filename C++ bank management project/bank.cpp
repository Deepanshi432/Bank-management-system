#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string name) {
        accountNumber = accNum;
        holderName = name;
        balance = 0.0;
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: ₹" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw Function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrawn: ₹" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Error: Insufficient balance.\n";
        }
    }

    // Display Function
    void display() {
        cout << "\n-----------------------------\n";
        cout << "      ACCOUNT DETAILS        \n";
        cout << "-----------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        // Using the Rupee symbol (Unicode) or "INR"
        cout << "Current Balance: Rs." << fixed << setprecision(2) << balance << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    string accNum, name;

    cout << "Enter Account Number: ";
    cin >> accNum;

    cout << "Enter Account Holder Name: ";
    cin.ignore(); // Clears the newline character from the previous input
    getline(cin, name);

    BankAccount account(accNum, name);

    int choice;
    double amount;

    do {
        cout << "\n===== Bank Management System =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        // Basic check to ensure the user enters a number
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch(choice) {
            case 1:
                cout << "Enter amount to deposit (Rs.): ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw (Rs.): ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.display();
                break;

            case 4:
                cout << "Thank you for using our Bank Management System!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while(choice != 4);

    return 0;
}