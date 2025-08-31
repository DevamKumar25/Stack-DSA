Start with definition

👉 What is a stack?
A stack is a linear data structure that follows LIFO (Last In First Out) order.

Example: A pile of plates — the last plate you put is the first you remove.

2. Explain design choices

I will implement stack using a fixed-size array (dynamic array also possible, but fixed-size is simple).

I’ll maintain three key things:

An array to store elements.

A variable cap for capacity (max size).

A variable top to track the index of the last element (initially -1 since stack is empty).


Overflow occurs when the stack is full and we try to push another element. For example, in a stack of size 3, if we already pushed 10, 20, 30, then pushing 40 will cause overflow."

"Underflow occurs when the stack is empty and we try to pop or peek. For example, if we already popped all elements, then calling pop again will cause underflow.



#include <bits/stdc++.h>
using namespace std;

struct Mystack {
    int *arr;   
    int cap;
    int top;
    
    Mystack(int c) {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    
    void push(int x) {
        if (top == cap - 1) {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    
    int pop() {
        if (top == -1) {
            cout << "Underflow" << endl;
            return INT_MIN;  // sentinel value
        }
        int res = arr[top];
        top--;
        return res;
    }
    
    int peek() {
        if (top == -1) {
            cout << "Underflow" << endl;
            return INT_MIN;  // sentinel value
        }
        return arr[top];
    }
    
    int size() {
        return (top + 1);
    }
    
    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Mystack s(5);
    s.push(5);
    s.push(25);
    s.push(35);
    s.push(45);
    s.push(55);
    
    cout << "Size of the stack is : " << s.size() << endl;
    cout << "Pop element : " << s.pop() << endl;
    cout << "Size of the stack is : " << s.size() << endl;
    cout << "Peek Element : " << s.peek() << endl;
    cout << "Is Empty : " << s.isEmpty() << endl;
    return 0;
}
