#include <iostream>
#include <string>
using namespace std;

const int m = 100; 

struct Task {
    string des;
    bool isCompleted;

    Task() : des(""), isCompleted(false) {} 
};

void viewTasks(Task t[], int c) {
    if (c == 0) 
    {
        cout << "\nNo Tasks to do.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < c; ++i) {
        cout << i + 1 << ". " << t[i].des 
             << " (" << (t[i].isCompleted ? "Completed" : "Pending") << ")\n";
    }
}

void addTask(Task t[], int& c) {
    if (c >= m) 
    {
        cout << "\nTask list is full. Can't add more tasks.\n";
        return;
    }

    cout << "\nEnter the task description: ";
    cin.ignore(); 
    getline(cin, t[c].des);
    t[c].isCompleted = false;
    c++;
    cout << "Task added successfully.\n";
}

void markTaskCompleted(Task t[], int c) {
    if (c == 0) 
    {
        cout << "\nNo tasks to mark as completed.\n";
        return;
    }

    viewTasks(t, c);
    int tn;
    cout << "\nEnter the task number to mark as completed: ";
    cin >> tn;

    if (tn > 0 && tn <= c)
    {
        t[tn - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(Task t[], int& c) {
    if (c == 0) 
    {
        cout << "\nNo tasks to remove.\n";
        return;
    }

    viewTasks(t, c);
    int tn;
    cout << "\nEnter the task number to remove: ";
    cin >> tn;

    if (tn > 0 && tn <= c) {
        for (int i = tn - 1; i < c - 1; ++i) 
        { 
            t[i] = t[i + 1];
        }
        c--; 
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    Task t[m]; 
    int c = 0; 
    bool to_do = true;

    cout << "Welcome to the To-Do List Manager\n";

    while (to_do) {
        cout << "\nMenu:\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                viewTasks(t, c);
                break;
            case 2:
                addTask(t, c);
                break;
            case 3:
                markTaskCompleted(t, c);
                break;
            case 4:
                removeTask(t, c);
                break;
            case 5:
                to_do = false;
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

