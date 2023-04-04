#include <iostream>
#include <chrono>

#define MAX_SIZE 20 // maximum size of the stack

using namespace std;
using namespace std::chrono;

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

    auto start_time1 = high_resolution_clock::now();

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

    auto end_time1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end_time1 - start_time1);
    cout << "Stack using Array " << duration1.count() /1000000.0<< " mili seconds" << endl;
   

    auto start_time2 = high_resolution_clock::now();

    cout<<endl;

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

    auto end_time2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end_time2 - start_time2);
    cout << "Stack using Linked list " << duration2.count()/1000000.0 << " miliseconds" << endl;

    return 0;
}
