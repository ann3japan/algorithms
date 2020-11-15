#include <iostream>

using namespace std;

class Queue {
    int front;
    int rear;
    int arr[5];
public:
    Queue() {
        front = rear = -1;
    }
    
    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if (rear == 4)
            return true;
        else
            return false;
    }
    
    void enqueue(int val) {
        if (isFull())
            cout << "The queue is full!" << endl;
        
        else if(isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        
        else {
            ++rear;
            arr[rear] = val;
        }
    }
    
    void dequeue() {
        if (isEmpty()) return;
        else if (front == rear)
            front = rear = -1;
        else {
            ++front;
        }
    }
    
    int front_element() {
        return arr[front];
    }
    
    void print() {
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(3);
    q.enqueue(5);
    q.dequeue();
    q.print();
    return 0;
}
