#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Student structure
struct Student {
    string name;
    int id;
};

// Node structure for doubly linked list
struct Node {
    Student data;
    Node* next;
    Node* prev;

    Node(string n, int i) {
        data.name = n;
        data.id = i;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class StudentList {
private:
    Node* head;
    Node* tail;
    int listSize;

public:
    StudentList() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    // Destructor to prevent memory leaks
    ~StudentList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 1. Add new student at the end
    void addStudent(string name, int id) {
        Node* newNode = new Node(name, id);

        if (head == nullptr) { // list is empty
            head = tail = newNode;
        } else {  //list exists
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        listSize++;
        cout << "Student added successfully!" << endl;
    }

    // 2. Insert at specific location (0-indexed)
    void insertAtLocation(string name, int id, int loc) {
        if (loc < 0 || loc > listSize) {
            cout << "Invalid range! Current size: " << listSize << endl;
            return;
        }

        Node* newNode = new Node(name, id);

        // Insert at beginning
        if (loc == 0) {
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        // Insert at end
        else if (loc == listSize) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        // Insert in middle
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
        cout << "Student inserted at position " << loc << " successfully!" << endl;
    }

    // 3. Search by ID
    void searchByID(int id) {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data.id == id) {
                cout << "\n=== Student Found ===" << endl;
                cout << "Position: " << position << endl;
                cout << "Name: " << current->data.name << endl;
                cout << "ID: " << current->data.id << endl;
                cout << "====================" << endl;
                return;
            }
            current = current->next;
            position++;
        }

        cout << "Student with ID " << id << " not found!" << endl;
    }

    // 4. Display all students
    void displayAll() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "\n=== All Students ===" << endl;
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            cout << position << ". "<< "\nName: " << current->data.name
                << "\nID: " << current->data.id << endl;
            current = current->next;
            position++;
        }

        cout << "Total students: " << listSize << endl;
        cout << "====================" << endl;
    }
};

int main() {
    StudentList list;
    int choice;
    string name;
    int id, position;

    do {
        cout << endl;
        cout << "1. Add new student (at end)" << endl;
        cout << "2. Insert student at position" << endl;
        cout << "3. Search student by ID" << endl;
        cout << "4. Display all students" << endl;
        cout << "0. Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                list.addStudent(name, id);
                break;

            case 2:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter position (0-based index): ";
                cin >> position;
                list.insertAtLocation(name, id, position);
                break;

            case 3:
                cout << "Enter student ID to search: ";
                cin >> id;
                list.searchByID(id);
                break;

            case 4:
                list.displayAll();
                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
