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
    Node* kReverse(Node* head, int k){
        if(head == NULL)
        return NULL;

    // step 1 reverse first k nodes :
    Node* curr = head;
     Node* prev = NULL;
     Node* next1 = NULL;
     int cnt = 0;
     while(curr!=NULL && cnt < k){
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
        cnt++;
    }

    // step 2 : 
    if(next1 != NULL){
        head->next = kReverse(next1,k);
    }
    // step 3 : return head of the reversed list
    return prev;
    
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
    list.insertAtHead(9);
    list.insertAtHead(10);
    list.insertAtHead(11);
    list.insertAtHead(12);
    list.insertAtHead(13);
    list.insertAtHead(14);

    list.display();

    list.head = list.kReverse(list.head,3);

    list.display();
    
}
