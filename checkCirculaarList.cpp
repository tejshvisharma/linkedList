#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor for Node to initialize with value
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class CircularLinkedList {
    

public:
    Node* head;
    int nodeCount; // To keep track of the number of nodes
    // Constructor for Circular Linked List
    CircularLinkedList() {
        head = NULL;
        nodeCount = 0;
    }

    // Function to insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        nodeCount++;

        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Circular link
            newNode->prev = newNode; // Circular link
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode; // Move head to the new node
        }
        
    }

    // Function to display the list
    void displayList() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        cout <<"[last Node] <-> ";
        do {
            cout << temp->data << " <->";
            temp = temp->next;
        } while (temp != head);
        cout<<"[first Node]";
        cout << endl;
    }
};
bool IsCircular(Node* head){
    Node* temp = head;
    while (temp->next!=NULL)
    {
        if(temp->next == head){
            cout<<"the list is a circular"<<endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main() {
    CircularLinkedList list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.insertAtHead(5);
    list.insertAtHead(6);
    list.insertAtHead(7);
    list.insertAtHead(8);
    list.insertAtHead(9);
    list.insertAtHead(10);
    list.insertAtHead(11);
    list.insertAtHead(12);
    list.insertAtHead(13);
    list.insertAtHead(14);


    list.displayList();
    IsCircular(list.head);




  
    
}