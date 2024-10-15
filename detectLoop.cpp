#include <iostream>
#include<map>
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

    void createLoop(int pos) {
        if (head == NULL) return;

        Node* temp = head;
        Node* loopNode = NULL;
        int count = 1;

        // Traverse the list to find the node at position 'pos'
        while (temp->next != NULL) {
            if (count == pos) {
                loopNode = temp;
                break;  // Save the node where the loop will start
            }
            temp = temp->next;
            count++;
        }

        // Create a loop by pointing the last node's next to the node at 'pos'
        if (loopNode != NULL) {
            temp->next = loopNode;
        }
    }
};

bool detectLoop(Node* head){
    Node* temp = head;
    if(temp == NULL)
    return false;

    map<Node*,bool> visited;
    while (temp->next != NULL)
    {
        if (visited[temp] == true)
    {
        cout<<"the list is looped  at "<<temp->data<<endl;
        return true;
    }
    visited[temp] = true;
    temp = temp->next;
    }
    cout<<"The list is not looped"<<endl;
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL)
    return NULL;
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL)
        fast = fast->next;

        slow = slow->next;

        if(slow == fast){
        cout<<"the list is looped"<<endl;
        return slow;
        }
    }
    cout<<"the list is not looped"<<endl;
    return NULL;
}
Node* getFirstLoopNode(Node* interSec, Node* head){
    if (interSec == NULL)
    {
        return NULL;
    }
    else
    {
        Node* slow = head;
        while (slow != interSec)
        {
            slow = slow->next;
            interSec = interSec->next;
        }
        return slow;
    }
}
void removeLoopInList(Node* loopNode,Node* head){
    if (loopNode != NULL){
        Node* prevNode = head;
        while (prevNode->next != loopNode)
        {
            prevNode = prevNode->next;
        }
        prevNode->next = NULL;
    }
    else
    return;
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
    list.createLoop(10);
    cout<<"The first node of the looped part of the list is "<<getFirstLoopNode(floydDetectLoop(list.head),list.head)->data;
    removeLoopInList(getFirstLoopNode(floydDetectLoop(list.head),list.head),list.head);
    list.displayList();
    




  
    
}