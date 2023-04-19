#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue q;

    int choice;
    do {
        cout << "1. Enqueue(Insert Rear)\n2. Dequeue(Remove front)\n3. Peek(Display front)\n4. Check Queue Status\n5. Check Queue Size\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                int val;
                cout << "Enter the value to be enqueued: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                if(q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Removed element: " << q.dequeue() << endl;
                break;
            case 3:
                if(q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Front element: " << q.peek() << endl;
                break;
            case 4:
                if(q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 5:
                if(q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Size of queue: " << q.getSize() << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);

    return 0;
}
