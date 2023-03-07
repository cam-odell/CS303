#ifndef SINGLE_LINKED_LIST_H_INCLUDED
#define SINGLE_LINKED_LIST_H_INCLUDED

#pragma once
#include <cstddef>
#include <vector>

template <typename Item_Type>
class Single_Linked_List {
private:
    // Inner struct representing a single node in the list
    struct Node {
        Item_Type data; // The item stored in this node
        Node* next; // Pointer to the next node in the list

        // Constructor to initialize a new node with the given item and next pointer
        Node(const Item_Type& data_item, Node* next_ptr = nullptr)
            : data(data_item), next(next_ptr) {}
    };
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
    size_t num_items; // The number of items in the list
public:
    // Constructor to initialize an empty list.
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}
    // Destructor to free all the memory allocated for the nodes in the list.
    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }
    Item_Type get(int index) const
    {
        if (index < 0 || index >= num_items)
            {
                throw std::out_of_range("Index out of range");
            }

        Node* curr = head;
        int curr_index = 0;

        while (curr != nullptr)
        {
            if (curr_index == index)
            {
                return curr->data;
            }
            curr = curr->next;
            curr_index++;
        }
    }
    // Adds a new item to the front of the list.
    void push_front(const Item_Type& item) {
        head = new Node(item, head);
        if (tail == nullptr) {
            tail = head;
        }
        ++num_items;
    }
    // Adds a new item to the end of the list.
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item, nullptr);
        if (tail == nullptr) {
            head = new_node;
        } else {
            tail->next = new_node;
        }
        tail = new_node;
        ++num_items;
    }
    // Removes the first item from the list.
    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* old_head = head;
        head = head->next;
        delete old_head;
        if (head == nullptr) {
            tail = nullptr;
        }
        --num_items;
    }
    // Removes the last item from the list.
    void pop_back() {
        if (tail == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
        --num_items;
    }
    size_t size() const {
        return num_items;
    }
    // Returns a reference to the first item in the list
    Item_Type& front() const {
        return head->data;
    }
    // Returns a reference to the last item in the list.
    Item_Type& back() const {
        return tail->data;
    }
    // Returns true if the list is empty, false otherwise.
    bool empty() const {
        return head == nullptr;
    }
    // Inserts a new item at the given index in the list.
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
        } else {
            Node* prev = head;
            size_t i = 1;
            while (prev->next != nullptr && i < index) {
                prev = prev->next;
                ++i;
            }
            prev->next = new Node(item, prev->next);
            if (prev->next->next == nullptr) {
                tail = prev->next;
            }
            ++num_items;
        }
    }
    bool remove(size_t index) {
        // If the index is greater than or equal to the number of items in the list, it is out of bounds
        if (index >= num_items) {
            return false;
        }
        // If the index is 0, remove the first item in the list by calling pop_front
        if (index == 0) {
            pop_front();
        } else {
            // Find the node that precedes the node to be deleted
            Node* prev = head;
            size_t i = 1;
            while (prev->next != nullptr && i < index) {
                prev = prev->next;
                ++i;
            }
            // a pointer to the node to be deleted
            Node* to_delete = prev->next;
            // Make the previous node point to the next node
            prev->next = to_delete->next;
            // If the next node is nullptr, the last node was deleted, so update tail to point to the new last node
            if (prev->next == nullptr) {
                tail = prev;
            }
            // Delete the node to be deleted
            delete to_delete;
            // Decrement the number of items in the list
            --num_items;
        }
        // Return true to indicate successful removal
        return true;
    }
    // Searches for the first occurrence of an item in the linked list
    // Returns the index of the item if found, or the number of items in the list if not found
    size_t find(const Item_Type& item) {
        // Start at the head of the list
        Node* curr = head;
        size_t i = 0;
        // Traverse the list until the item is found or the end of the list is reached
        while (curr != nullptr && curr->data != item) {
            curr = curr->next;
            ++i;
        }
        // If the item is not found, return the number of items in the list
        // Otherwise, return the index of the item
        return curr == nullptr ? num_items : i;
    }
};

#endif // SINGLE_LINKED_LIST_H_INCLUDED
