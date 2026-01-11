#include <iostream>
#include <limits>

using namespace std;

//^ Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    //^Destructor to prevent memory leaks
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    //^1. Add new element at the end
    void addElement(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) { //?list is empty
            head = tail = newNode;
        } else {  //?list exists
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        listSize++;
        cout << "Element added successfully!" << endl;
    }

    //^ 2. Insert at specific location (0-indexed)
    void insertAtLocation(int data, int loc) {
        if (loc < 0 || loc > listSize) {
            cout << "Invalid range! Current size: " << listSize << endl;
            return;
        }

        Node* newNode = new Node(data);

        //^ Insert at beginning
        if (loc == 0) {
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        //^ Insert at end
        else if (loc == listSize) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        //^ Insert in middle
        else 
        {
            Node* current = head;
            for (int i = 0; i < loc; i++) {
                current = current->next;
            }

            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }

        listSize++;
        cout << "Element inserted at position " << loc << " successfully!" << endl;
    }

    //^ 3. Search by data value
    void searchByValue(int value) {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                cout << "\n=== Element Found ===" << endl;
                cout << "Position: " << position << endl;
                cout << "Data: " << current->data << endl;
                cout << "====================" << endl;
                return;
            }
            current = current->next;
            position++;
        }

        cout << "Element with value " << value << " not found!" << endl;
    }

    //^ 4. Display all elements
    void displayAll() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "\n=== All Elements ===" << endl;
        Node* current = head;
        int position = 0;
        cout << "Values of DLL: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
            position++;
        }

        cout << "Total elements: " << listSize << endl;
        cout << "====================" << endl;
    }

    // 5. Bubble Sort by data
    void bubbleSort() {
        
        //^ if a list is empty or has only one element, no need to sort
        if (head == nullptr || head->next == nullptr) {
            cout << "List is empty or has only one element.\nNo sorting needed!" << endl;
            return;
        }

        bool swapped;
        Node* current;

        do {
            swapped = false;
            current = head;

            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    //^ Swap the data
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;

                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

        cout << "List sorted successfully!" << endl;
    }
};

int main() {
    LinkedList list;
    int choice;
    int data, position;

    do {
        cout << endl;
        cout << "1. Add new element (at end)" << endl;
        cout << "2. Insert element at position" << endl;
        cout << "3. Search element by value" << endl;
        cout << "4. Display all elements" << endl;
        cout << "5. Apply bubble sort " << endl;
        cout << "0. Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data value: ";
                cin >> data;
                list.addElement(data);
                break;

            case 2:
                cout << "Enter data value: ";
                cin >> data;
                cout << "Enter position (0-based index): ";
                cin >> position;
                list.insertAtLocation(data, position);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> data;
                list.searchByValue(data);
                break;

            case 4:
                list.displayAll();
                break;

            case 5:
                list.bubbleSort();
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
