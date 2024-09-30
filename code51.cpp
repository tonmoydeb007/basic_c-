#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to add a node at the beginning
Node* add_at_beg(Node* head, int d) {
    Node *ptr = new Node(); // Use 'new' in C++
    ptr->data = d;
    ptr->next = head;
    return ptr;
}

// Function to add a node at the end
void add_at_end(Node *head, int data) {
    Node *temp = new Node();
    Node *ptr = head;

    temp->data = data;
    temp->next = nullptr;

    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Function to add a node at a specific position
void add_at_pos(Node* head, int data, int pos) {
    Node *ptr = head;
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    pos--;
    while(pos != 0 && ptr != nullptr) {
        ptr = ptr->next;
        pos--;
    }
    if (ptr != nullptr) {
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

int main() {
    // Create head node
    Node *head = new Node();
    head->data = 25;
    head->next = nullptr;

    // Perform various operations on the list
    add_at_end(head, 18);
    add_at_end(head, 50);

    int data = 17, position = 3;
    add_at_pos(head, data, position);

    head = add_at_beg(head, 50);

    // Print the list
    Node *ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    cout << endl;

    // Free allocated memory
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp; // Use 'delete' in C++ to free memory
    }

    return 0;
}
