
#include <iostream>
#include <cmath>

using namespace std;

// function prototypes
void Heapify(int A[], int i, int n);
void BuildMaxHeap(int A[], int n);
void Heapsort(int A[], int n);
void swap(int &a, int &b); // pass by reference

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Heapsort(A, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

// function to perform heapsort
void Heapsort(int A[], int n) {
    BuildMaxHeap(A, n); // build max heap
    for(int i = n - 1; i >= 1; i--) { // for each element in the heap
        swap(A[0],A[i]); // swap the first (max) element with the ith element
        Heapify(A, 0, i); // restore the heap property
    }
}

// function to build a max heap from an unsorted array
void BuildMaxHeap(int A[], int n) {
    for(int i = floor(n/2) - 1; i >= 0; i--) { // for each non-leaf node in the heap
        Heapify(A, i, n); // restore the heap property
    }
}

// function to restore the heap property for a subtree rooted at i
void Heapify(int A[], int i, int n) {
    int left_index = 2 * i + 1; // index of left child
    int right_index = 2 * i + 2; // index of right child
    int max_index = i; // index of largest element
    if(left_index < n && A[left_index] > A[max_index]) { // if left child is larger than parent
        max_index = left_index; // update max_index
    }
    if(right_index < n && A[right_index] > A[max_index]) { // if right child is larger than parent or left child
        max_index = right_index; // update max_index
    }
    if(max_index != i) { // if parent is not the largest element
        swap(A[i],A[max_index]); // swap parent with largest element
        Heapify(A, max_index, n); // restore the heap property for the subtree rooted at max_index
    }
}

// function to swap two elements
void swap(int &a, int &b){ // pass by reference
    int temp = a;
    a = b;
    b = temp;
}

