#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // queue size set to 100 by default

class Queue {
private:
    int arr[MAX_SIZE]; // array for elements
    int front; // index queue front
    int rear; // index queue rear
    int size; // queue size

public:
    Queue();
    void enqueue(int element); // add an element to the back of the queue
    int dequeue(); // remove an element from the front of the queue
    int peek(); // get element from front of queue without modifying queue
    bool isEmpty(); // check if queue empty
    int getSize(); // get current size of queue
};

Queue::Queue() {
    front = rear = -1; // initialize front and rear indices
    size = 0; // initialize size
}

void Queue::enqueue(int element) {
    if (size == MAX_SIZE) { // check if the queue is full
        cout << "Queue is full. Cannot insert more elements." << endl;
        return;
    }

    if (front == -1) { // check if queue empty
        front++; // if empty, set front index to 0
    }

    rear++; // increment rear index
    arr[rear] = element; // add new element to back of queue
    size++; // increment size of queue
}

int Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return -1;
    }

    int element = arr[front];
    front++;
    size--; // decrement size of queue

    return element; // return removed element
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
