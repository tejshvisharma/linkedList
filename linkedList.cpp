#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to insert at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert at a specific position
    void insertAtPosition(int pos, int val) {
        if (pos == 1) {
            insertAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node by value
    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Value not found in the list!" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to search for a value in the list
    bool search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    int choice, value, pos;
    
    while (true) {
        cout << "\n--- Linked List Operations Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Search\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            list.insertAtHead(value);
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insertAtTail(value);
            break;
        case 3:
            cout << "Enter position and value to insert: ";
            cin >> pos >> value;
            list.insertAtPosition(pos, value);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value))
                cout << "Value found in the list!" << endl;
            else
                cout << "Value not found in the list!" << endl;
            break;
        case 6:
            list.display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
