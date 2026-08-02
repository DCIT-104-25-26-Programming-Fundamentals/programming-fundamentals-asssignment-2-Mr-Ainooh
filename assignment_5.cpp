#include <iostream>
using namespace std;

void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

void printMultipleTables(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    for (int num = 1; num <= n; num++) {
        printSingleTable(num);
        if (num < n) {
            cout << "------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n=============================" << endl;
        cout << "  MULTIPLICATION TABLES" << endl;
        cout << "=============================" << endl;
        cout << "1. Single Table (1-12)" << endl;
        cout << "2. Multiple Tables (1 to N)" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        if (choice == 1) {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            
            if (num <= 0) {
                cout << "Error: N must be a positive integer." << endl;
            } else {
                printSingleTable(num);
            }
        }
        else if (choice == 2) {
            int n;
            cout << "Enter N: ";
            cin >> n;
            printMultipleTables(n);
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}