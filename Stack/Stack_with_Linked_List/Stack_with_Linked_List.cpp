#include <iostream>
#include <string>
using namespace std;

// Student structure
struct Student {
    string name;
    int id;
};


struct Node {
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = nullptr;
    }
};

class Stack_LinkedList {
private:
    Node* top;

public:
    // Constructor
    Stack_LinkedList() {
        top = nullptr;
    }

    // Destructor
    ~Stack_LinkedList() {
        while (!isEmptyStack()) {
            pop();
        }
    }

    // Check if stack is empty
    bool isEmptyStack() {
        return top == nullptr;
    }

    // Push student
    void push(Student s) {
        Node* newNode = new Node(s);
        newNode->next = top;
        top = newNode;
    }

    // Pop student
    Student pop() {
        if (isEmptyStack()) {
            return {"", -1};
        }

        Student popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return popped;
    }

    // Get top student
    Student getTop() {
        if (isEmptyStack()) {
            return {"", -1};
        }
        return top->data;
    }

    // Print stack
    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << "[Name: " << temp->data.name
                << ", ID: " << temp->data.id << "] ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get student with maximum ID
    Student getMax() {
        if (isEmptyStack()) {
            return {"", -1};
        }

        Node* temp = top;
        Student maxStudent = top->data;

        while (temp != nullptr) {
            if (temp->data.id > maxStudent.id) {
                maxStudent = temp->data;
            }
            temp = temp->next;
        }

        return maxStudent;
    }
};

int main() {
    Stack_LinkedList s;

    // Create students
    Student s1 = {"Ali", 101};
    Student s2 = {"Sara", 205};
    Student s3 = {"Omar", 150};
    Student s4 = {"Lina", 300};

    // Push students onto stack
    s.push(s1);
    s.push(s2);
    s.push(s3);
    s.push(s4);

    // Display stack
    cout << "Students in the stack:" << endl;
    s.print();

    cout << "=================" << endl;

    // Get max student
    Student maxStudent = s.getMax();
    cout << "Student with maximum ID: "<< maxStudent.name << " (" << maxStudent.id << ")" << endl;
    cout << "=================" << endl;

    // Pop student
    Student popped = s.pop();
    cout << "Popped student: " << popped.name << " (" << popped.id << ")" << endl;

    cout << "=================" << endl;

    // Stack after pop
    cout << "Stack after popping:" << endl;
    s.print();

    return 0;
}
