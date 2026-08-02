#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    
    do {
        cout << "\n============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            string task;
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added: \"" << task << "\"" << endl;
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "Your To-Do list is empty." << endl;
            } else {
                cout << "Your Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            if (tasks.empty()) {
                cout << "Your To-Do list is empty." << endl;
            } else {
                cout << "Your Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
                int taskNum;
                cout << "Enter task number to delete: ";
                cin >> taskNum;
                
                if (taskNum < 1 || taskNum > tasks.size()) {
                    cout << "Error: Invalid task number." << endl;
                } else {
                    string deletedTask = tasks[taskNum - 1];
                    tasks.erase(tasks.begin() + taskNum - 1);
                    cout << "Task \"" << deletedTask << "\" has been removed." << endl;
                }
            }
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
