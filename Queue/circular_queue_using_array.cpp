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
        if ((rear + 1) % 5 == front)
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
            rear = (rear + 1) % 5;
            arr[rear] = val;
        }
    }
    
    void dequeue() {
        if (isEmpty())
            cout << "The queue is empty!" << endl;
        else if (front == rear)
            front = rear = -1;
        else {
            front = (front + 1) % 5;
        }
    }
    
    int front_element() {
        return arr[front];
    }
    
    void print() {
        int cnt = (rear + 5 - front) % 5;
        for (int i = 0; i <= cnt; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(5);
    q.print();
    q.enqueue(5);
    q.print();
    return 0;
}
