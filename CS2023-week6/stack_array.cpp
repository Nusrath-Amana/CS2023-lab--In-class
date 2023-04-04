#include <iostream>

#define MAX_SIZE 20 // maximum size of the stack

using namespace std;

class Stack1 {
private:
    int arr[MAX_SIZE];
    int top; // index of the top element of the stack
    int size; // maximum size of the stack
public:
    Stack1() {
        top = -1; // initialize the top index to -1
        size = MAX_SIZE; // initialize the maximum size of the stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return 0;
        }
        int poppedElement = top;
        top--;
        return poppedElement;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {

    Stack1 s1;

    s1.push(8);
    s1.push(10);
    s1.push(5);
    s1.push(11);
    s1.push(15);
    s1.push(23);
    s1.push(6);
    s1.push(18);
    s1.push(20);
    s1.push(17);
    s1.display(); 

    for (int i=0; i<5; i++)  //pop 5 times
        s1.pop();
    s1.display(); 

    s1.push(4);
    s1.push(30);
    s1.push(3);
    s1.push(1);
    s1.display();

    return 0;
}

