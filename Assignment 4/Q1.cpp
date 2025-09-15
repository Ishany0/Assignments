#include <iostream>
#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        std::cout << "Enqueued: " << val << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    void peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Front element: " << arr[front] << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        std::cout << "\n--- Queue Menu ---\n";
        std::cout << "1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Is Full\n5. Display\n6. Peek\n0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                std::cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                std::cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
