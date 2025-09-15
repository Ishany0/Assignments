#include <iostream>
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
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
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
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
    CircularQueue cq;
    int choice, val;
    do {
        std::cout << "\n--- Circular Queue Menu ---\n";
        std::cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> val;
                cq.enqueue(val);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                std::cout << (cq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 4:
                std::cout << (cq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cq.peek();
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
