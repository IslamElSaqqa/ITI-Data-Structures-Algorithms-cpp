#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;
    int Size;

public:
    // Constructor
    LinkedQueue() {
        front = rear = nullptr;
        Size = 0;
    }

    // Destructor
    ~LinkedQueue() {
        while (!IsEmpty()) {
            Dequeue();
        }
    }

    // Check if queue is empty
    bool IsEmpty() {
        return front == nullptr && Size == 0;
    }

    // Enqueue
    void Enqueue(int data) {
        Node* newNode = new Node(data);

        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        Size++;
    }

    // Dequeue
    int Dequeue() {
        if (IsEmpty()) {
            cout << "Can't retrieve the data" << endl;
            return -1;
        }

        int result = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        Size--;

        if (front == nullptr) {
            rear = nullptr;
        }

        return result;
    }

    // Display queue elements
    void Display() {
        LinkedQueue temp;
        int x;

        while (!IsEmpty()) {
            x = Dequeue();
            cout << x << " ";
            temp.Enqueue(x);
        }

        // Restore queue
        while (!temp.IsEmpty()) {
            Enqueue(temp.Dequeue());
        }

        cout << endl;
    }

    // Get size
    int GetSize() {
        return Size;
    }
};

int main() {
    LinkedQueue Q;

    Q.Enqueue(10);
    Q.Enqueue(13);
    Q.Enqueue(16);
    Q.Enqueue(19);
    Q.Enqueue(20);

    cout << "Queue elements: ";
    Q.Display();

    cout << "Dequeued element: " << Q.Dequeue() << endl;

    cout << "Queue after deletion: ";
    Q.Display();

    return 0;
}
