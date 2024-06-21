#include <iostream>
#include <stdlib.h>

struct Node {
    int ID;
    int index;  // Index of the node in the list
    Node* next;
    Node* previous;
};

Node* start = NULL;
Node* end = NULL;

// Function to insert a node at the end of the doubly linked list
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ID = value;
    newNode->index = 1; // Initialize index, will be updated later
    newNode->next = NULL;
    newNode->previous = NULL;

    if (start == NULL) {
        // If the list is empty
        start = newNode;
        end = newNode;
    }
    else {
        // Update the index for the new node
        newNode->index = end->index + 1;

        // Adjust the links for the new node
        end->next = newNode;
        newNode->previous = end;
        end = newNode;
    }
}

// Function to print the doubly linked list
void printList() {
    Node* current = start;
    while (current != NULL) {
        std::cout << "Node " << current->index << ": " << current->ID << std::endl;
        current = current->next;
    }
}

// Partitioning the list for Quick Sort
Node* partition(Node* low, Node* high) {
    int pivot = high->ID;
    Node* i = low->previous;

    for (Node* j = low; j != high; j = j->next) {
        if (j->ID <= pivot) {
            i = (i == NULL) ? low : i->next;

            // Swap nodes and update indexes
            int tempID = i->ID;
            i->ID = j->ID;
            j->ID = tempID;
            int tempIndex = i->index;
            i->index = j->index;
            j->index = tempIndex;
        }
    }

    i = (i == NULL) ? low : i->next;

    // Swap nodes and update indexes for the pivot node
    int tempID = i->ID;
    i->ID = high->ID;
    high->ID = tempID;
    int tempIndex = i->index;
    i->index = high->index;
    high->index = tempIndex;

    return i;
}

// Quick Sort on Doubly Linked List
void quickSort(Node* low, Node* high) {
    if (high != NULL && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot->previous);
        quickSort(pivot->next, high);
    }
}

int main() {
    int choice;
    int value;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Insert a node\n";
        std::cout << "2. Print the list\n";
        std::cout << "3. Sort using Quick Sort\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the value to insert: ";
            std::cin >> value;
            insert(value);
            break;
        case 2:
            std::cout << "Current List:\n";
            printList();
            break;
        case 3:
            if (start != NULL) {
                quickSort(start, end);
                std::cout << "Sorted List (Quick Sort):\n";
                printList();
            }
            else {
                std::cout << "List is empty. Insert nodes first.\n";
            }
            break;
        case 4:
            std::cout << "Exiting the program.\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}