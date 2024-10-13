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
    

public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    // Function to insert at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
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
        cout << "NULL" << endl<<endl;
    }

    // function to reverse the list iteratively :
    void reverseListIteratively(){
        if (head == NULL || head->next == NULL)
        {
            cout<<"Reversal of the list is not applicable"<<endl;
            return;
        }
        
     Node* temp = head;
     Node* prev = NULL;
     Node* next1;
     while (temp->next!=NULL){
       next1 = temp->next; 
       temp->next = prev;
       prev = temp;
       temp = next1;
     }
     temp->next = prev;
     head = temp;
     cout<<"The List is successfully Reversed"<<endl;
    }

    void reverseListRecursively(Node* curr, Node* prev = NULL){
        if (curr == NULL || curr->next == NULL)
        {
            curr->next = prev;
            head = curr;
        cout<<"The List is successfully Reversed"<<endl;
            return;
        }
        
        Node* temp = curr;
        Node* next1;
          next1 = temp->next; 
          temp->next = prev;
          prev = temp;
          temp = next1;
        reverseListRecursively(temp, prev);
        }

    Node* reverseListInSort(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Base case: return if the list is empty or has one element
    }

    Node* smallHead = reverseListInSort(head->next);  // Recursively reverse the rest of the list
    head->next->next = head;  // Set the next node's next to the current node
    head->next = NULL;  // Break the current node's next link to avoid cycles

    return smallHead;  // Return the new head of the reversed list
}



};


int main() {
    LinkedList list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.insertAtHead(5);
    list.insertAtHead(6);
    list.insertAtHead(7);
    list.insertAtHead(8);

    list.display();
    list.head = list.reverseListInSort(list.head);
    // Call this outside the recursive function for clarity
    cout << "The List is successfully Reversed" << endl;
    list.insertAtHead(10);

    list.display();
    
}
