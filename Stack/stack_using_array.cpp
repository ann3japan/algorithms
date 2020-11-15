#include <iostream>

using namespace std;

class Stack {
    int top;
    int arr[5];
public:
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        if (top == -1) return true;
        else return false;
    }
    
    bool isFull() {
        if (top == 4) return true;
        else return false;
    }
    
    void push(int val) {
        if(!isFull()) {
            ++top; // top = 0;
            arr[top] = val;
        } else
            cout << "Stack overflow!" << endl;
    }
    
    void pop() {
        if (!isEmpty())
            --top;
        else
            cout << "Stack underflow!" << endl;
    }
    
    int top_element() {
        return arr[top];
    }
    
    void print_elements() {
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(3);
    s.pop();
    s.print_elements();
    return 0;
}
