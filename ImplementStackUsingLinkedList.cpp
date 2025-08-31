Start with the problem definition
👉 "I was asked to implement a stack using a linked list. A stack works on the LIFO (Last In, First Out) principle, which means the last element inserted is the first to be removed


2. Explain the data structure design

👉 "I created a Node structure to represent each element in the stack. Each node contains two fields:

data: stores the actual value.

next: stores the pointer to the next node."

👉 "Then, I created a Mystack structure that maintains two important pieces of information:

head: pointer to the top element of the stack.

size: the current number of elements in the stack."





  3. Walk through each function

Push (Insertion)
"When we push an element, I create a new node and make it the new head. Its next pointer links to the old head. Time complexity is O(1)."

Pop (Deletion)
"When we pop, we remove the head node, move the head pointer to the next node, and delete the old head. This also works in O(1)."

Peek (Top element)
"Peek simply returns the head’s data, without deleting it."

isEmpty
"It checks whether head is NULL. If it is, the stack is empty."

Size
"I maintain a counter (size) which I increment during push and decrement during pop, so returning size is an O(1) operation."



  I implemented a stack using a singly linked list. Each node stores the data and pointer to the next node. 
  The head pointer represents the top of the stack. Push inserts a new node at the head, Pop removes the head node, Peek returns the head value, and Size is tracked in O(1). 
  This implementation supports dynamic size growth, unlike array-based stacks, and each operation runs in constant time



#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        next = NULL;
    }
};

struct MyStack {
    Node* head;
    int sz;   // renamed to avoid conflict
    
    MyStack() {
        head = NULL;
        sz = 0;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        sz++;
    }
    
    int pop() {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return INT_MAX;
        }
        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete(temp);
        sz--;
        return res;
    }
    
    int getSize() {
        return sz;
    }
    
    bool isEmpty() {
        return (head == NULL);
    }
    
    int peek() {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return INT_MAX;
        }
        return head->data;
    }
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Peek: " << s.peek() << endl;
    cout << "Size: " << s.getSize() << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;

    cout << "Size: " << s.getSize() << endl;
    cout << "Is Empty : " << s.isEmpty() << endl;

    s.pop();      // removes last element
    s.pop();      // Underflow

    return 0;
}
