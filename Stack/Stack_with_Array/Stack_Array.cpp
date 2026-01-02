#include <iostream>
using namespace std;

#define CAPACITY 100
class Stack_Array{
    int top; // initially
    int items[CAPACITY]; // top > -1 and top < Capacity + 1, 

    public:
        Stack_Array():top(-1){}
    
        int isEmptyStack() 
        {
            return top < 0;  //underflow
        };

        int isFullStack()
        {
            return top > CAPACITY; // overflow
        };
    
        // Basic Functions (push and pop)
        // push an element onto the stack
        void push(int d)
        {
            // check if the list is full
            if(isFullStack())
            {
                cout << "Stack is full on Push";
            }
            else
            {
                items[++top] = d;
            }
        };

        // removes and returns the last inserted element from the stack
        int pop()
        {
            int popped = -1;
            if (isEmptyStack())
            {
                return popped;
            }
            else
            {
                popped = items[--top];
            }

            return popped;
        };
    
        //Auxillary Functions (isEmptyStack, isFullStack, getTop, print)
        int getTop() 
        {
            int popped = -1;
            if (isEmptyStack())
            {
                return popped;
            }
            else
            {
                popped = items[top];
            }
            return popped;
        };
    
        void print() 
        {
            for (int i = top; i >= 0; i--)
            {
                cout << "[";
                cout<<items[i] << " ";
                cout << "]";
            }
            cout << endl;
        };

        // get the maximum value from the stack without popping
        int getMax()
        {
            int max = items[0];
            if(!isEmptyStack ())
            {
                for (int i = 1; i <= top; i++)
                {
                    if (items[i] > max)
                        max = items[i];
                }
                    return max;
        }
        return -1;
    }
    };

int main ()
{
    Stack_Array s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << "Elements of the stack before pop: ";
    s.print();
    cout << "=================" << endl;
    cout << "Maximum value in the stack before Pop: " << s.getMax() << endl;
    cout << "=================" << endl;
    cout << "Elements of the stack after popping: ";
    int popped = s.getTop();
    s.pop();
    s.print();
    cout << "=================" << endl;
    cout << "The popped value= "<< popped << endl;
    cout << "Maximum Value of the stack after Pop: " << s.getMax() << endl;
}
