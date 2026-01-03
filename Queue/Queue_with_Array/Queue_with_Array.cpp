#include <iostream>
using namespace std;

#define CAPACITY 5

class ArrayQueue {
private:
    int items[CAPACITY];
    int rear;   // points to the next empty position
    int Size;   // current number of elements

public:
    // Constructor
    ArrayQueue() {
        rear = 0;
        Size = 0;
    }

    // Check if queue is empty
    bool IsEmpty() {
        return Size == 0;
    }

    // Check if queue is full
    bool IsFull() {
        return Size == CAPACITY;
    }

    // Enqueue
    void Enqueue(int data) {
        if (IsFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        items[rear] = data;
        rear++;
        Size++;
    }

    int Dequeue() {
        int retval = -1;
        if (rear > 0) { //List Exists
            retval = items[0]; 
            for (int i = 0; i < rear - 1; i++) {
                items[i] = items[i + 1]; //shift
            }
            rear--;
            Size--;
        }
        else
        {
            cout << "Can't retrieve the data, queue is empty" << endl;
        }
        return retval;
    }

    // Display the queue
    void Display() {
        for (int i = 0; i < rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    // Get current size
    int GetSize() {
        return Size;
    }
};

int main() {
    ArrayQueue Q;

    Q.Enqueue(10);
    Q.Enqueue(13);
    Q.Enqueue(16);
    Q.Enqueue(19);
    Q.Enqueue(20);

    cout << "Queue elements before Deletion: ";
    Q.Display();

    cout << "Dequeued element: " << Q.Dequeue() << endl;

    cout << "Queue after deletion: ";
    Q.Display();

    return 0;
}
