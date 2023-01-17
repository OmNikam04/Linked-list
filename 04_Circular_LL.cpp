#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = nullptr;
    }
};

void insertAtHead(node* &head, int val){
    //if there is not any node in Clinked list then 
    //then just create new node and add it as head
    node* newNode = new node(val);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head, int val){

    // if linked list is empty
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }
    //create new node
    node *newNode = new node(val);

    node* temp = head;

    //in circular linked list tail->next is head
    while(temp->next != head){
        temp = temp->next;
    }
    //now our temp is tail of our list
    // insert after it
    temp->next = newNode;
    newNode->next = head;

}

void display(node* &head){
    node *temp = head;
    // it is necessary to use do..while loop for display because
    // while(temp->next!=head) will break the loop when we are on last node so last node won't be printing
    // while(temp!=head) we won't enter the loop at start as temp is head atbthe beginning
    // so used do...while loop
    
    do{
        cout<<temp->data<<" ";
        temp= temp->next;
    }while(temp!=head);
    cout<<endl;
}

void deleteAtHead(node* &head){
    // get the last node of linked list so we can point head to it later
    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    //now our temp contains last node of our list
    
    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(node* &head, int pos){

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    // get the node just before the node to be deleted
    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    node *todelete = temp->next;
    temp->next=temp->next->next ;

    delete todelete;
}

int main()
{
     node *head = NULL;
     insertAtTail(head, 10);
     insertAtTail(head, 20);
     insertAtTail(head, 30);
     insertAtTail(head, 40);
     insertAtTail(head, 50);
     display(head);
     insertAtHead(head, -10);
     insertAtHead(head, -20);
     display(head);

     deletion(head, 3);
     display(head);
    return 0;
}