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

    int middleOfList(Node* head){
        Node* temp = head;
        int nodeCount = 0;
        do{
            nodeCount++;
            temp = temp->next;
        }while(temp!= NULL);
        temp = head;
        for (int i=0; i < (nodeCount/2); i++)
        {
            temp = temp->next;
        }
        return temp->data;
        

        
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

    list.display();
  
    

    list.display();
    int middleListData = list.middleOfList(list.head);
    cout<<"The middle of the list is : "<<middleListData<<endl;
    
}
