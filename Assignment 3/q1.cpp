#include <iostream>
using namespace std;
#define SIZE 100 
class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
// Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push.\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed into the stack.\n";
        }
    }
 // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
        } else {
            cout << arr[top--] << " popped from the stack.\n";
        }
    }
// Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
 // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == SIZE - 1;
    }
    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n*** Stack Menu ***\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
