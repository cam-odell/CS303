#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

const int MAX_SIZE = 100;

class Queue {
    private:
        int arr[MAX_SIZE];
        int front;
        int rear;
        int size;

    public:
        Queue();
        void enqueue(int element);
        int dequeue();
        int peek();
        bool isEmpty();
        int getSize();
};

Queue::Queue() {
    front = rear = -1;
    size = 0;
}

void Queue::enqueue(int element) {
    if (size == MAX_SIZE) {
        cout << "Queue is full. Cannot insert more elements." << endl;
        return;
    }

    if (front == -1) {
        front++;
    }

    rear++;
    arr[rear] = element;
    size++;
}

int Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return -1;
    }

    int element = arr[front];
    front++;
    size--;

    return element;
}

int Queue::peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Cannot peek elements." << endl;
        return -1;
    }

    return arr[front];
}

bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

int Queue::getSize() {
    return size;
}

#endif
