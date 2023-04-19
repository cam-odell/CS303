#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue q; //instantiate queue

    int choice;
    do {
        // Queue menu options for user
        cout << "1. Enqueue(Insert Rear)\n2. Dequeue(Remove front)\n3. Peek(Display front)\n4. Check Queue Status\n5. Check Queue Size\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                int val;
                // Prompt the user for value
                cout << "Enter the value to be enqueued: ";
                cin >> val;
                q.enqueue(val); // Calling the enqueue method of the 'q' instance to add the value to the queue
                break;
            case 2:
                if(q.isEmpty()) // Check if the queue is empty
                    cout << "Queue is empty.\n";
                else
                    cout << "Removed element: " << q.dequeue() << endl; // dequeue to remove and return the front element
                break;
            case 3:
                if(q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Front element: " << q.peek() << endl; //  peek to return the front element without removing it
                break;
            case 4:
                if(q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 5:
                if(q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Size of queue: " << q.getSize() << endl; // getSize method to return the size of the queue
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // invalid choice error message
        }
    } while(choice != 6); // loop until exit(choice/case 6)

    return 0;
}
