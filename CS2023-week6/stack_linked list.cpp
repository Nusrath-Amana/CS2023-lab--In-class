#include <iostream>

#define MAX_SIZE 20 // maximum size of the stack

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack2 {
private:
    Node* top; // pointer to the top element of the stack
public:
    Stack2() {
        top = nullptr; // initialize the top pointer to null
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return 0;
        }
        int poppedElement = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedElement;
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    
    Stack2 s2;

    s2.push(8);
    s2.push(10);
    s2.push(5);
    s2.push(11);
    s2.push(15);
    s2.push(23);
    s2.push(6);
    s2.push(18);
    s2.push(20);
    s2.push(17);
    s2.display(); 

    for (int i=0; i<5; i++)  //pop 5 times
        s2.pop();
    s2.display(); 

    s2.push(4);
    s2.push(30);
    s2.push(3);
    s2.push(1);
    s2.display();


    return 0;
}