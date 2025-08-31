Start with definition

👉 What is a stack?
A stack is a linear data structure that follows LIFO (Last In First Out) order.

Example: A pile of plates — the last plate you put is the first you remove.



I can implement stack using raw arrays (with fixed capacity), but in modern C++, I prefer using vector because it manages memory automatically and reduces chances of bugs like overflow/underflow.


All basic stack operations (push, pop, peek, size, isEmpty) work in O(1) time. The space complexity is O(n), where n is the number of elements in the stack.
    In an array-based stack, we pre-allocate memory, while in a vector-based implementation, memory grows dynamically as needed.
    
    
    #include <bits/stdc++.h>
using namespace std;

struct MyStack {
    vector<int> arr;   // dynamic array (vector)
    int cap;           // maximum capacity

    MyStack(int c) {
        cap = c;
    }

    void push(int x) {
        if (arr.size() == cap) {
            cout << "Overflow\n";
            return;
        }
        arr.push_back(x);
    }

    int pop() {
        if (arr.empty()) {
            cout << "Underflow\n";
            return INT_MIN;
        }
        int res = arr.back();
        arr.pop_back();
        return res;
    }

    int peek() {
        if (arr.empty()) {
            cout << "Underflow\n";
            return INT_MIN;
        }
        return arr.back();
    }

    int size() {
        return arr.size();
    }

    bool isEmpty() {
        return arr.empty();
    }
};

int main() {
    MyStack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // Overflow

    cout << "Size: " << s.size() << endl;
    cout << "Top element: " << s.peek() << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;

    cout << "Size: " << s.size() << endl;
    cout << "Is Empty: " << s.isEmpty() << endl;

    return 0;
}


