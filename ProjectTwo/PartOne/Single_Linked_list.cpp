#include <iostream>
#include "single_linked_list.h"

int main() {
    Single_Linked_List<int> my_list;

    // Test push_front, push_back, pop_front, pop_back, front, back, empty
    std::cout << "Testing push_front, push_back, pop_front, pop_back, front, back, and empty:\n";
    std::cout << "The list is " << (my_list.empty() ? "empty" : "not empty") << std::endl;
    my_list.push_front(1);
    my_list.push_back(2);
    my_list.push_back(3);
    std::cout << "The list is " << (my_list.empty() ? "empty" : "not empty") << std::endl;
    std::cout << "The front of the list is " << my_list.front() << std::endl;
    std::cout << "The back of the list is " << my_list.back() << std::endl;
    my_list.pop_front();
    std::cout << "After popping the front of the list, the front is " << my_list.front() << std::endl;
    my_list.pop_back();
    std::cout << "After popping the back of the list, the back is " << my_list.back() << std::endl;

    // Test insert and remove
    std::cout << "\nTesting insert and remove:\n";
    my_list.insert(0, 0);
    my_list.insert(2, 4);
    my_list.insert(2, 3);
    std::cout << "The list is now: ";
    for (size_t i = 0; i < my_list.size(); ++i) {
        std::cout << my_list.get(i) << " ";
    }
    std::cout << std::endl;
    my_list.remove(0);
    my_list.remove(2);
    std::cout << "After removing the first and third elements, the list is now: ";
    for (size_t i = 0; i < my_list.size(); ++i) {
        std::cout << my_list.get(i) << " ";
    }
    std::cout << std::endl;

    // Test find
    std::cout << "\nTesting find:\n";
    std::cout << "The index of 2 in the list is " << my_list.find(2) << std::endl;
    std::cout << "The index of 5 in the list is " << my_list.find(5) << std::endl;

    return 0;

}

