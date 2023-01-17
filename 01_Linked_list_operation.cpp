#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void inserAtBegining(int);
    void insertAtEnd(int);
    void insertAfterNode(int, int);
    void deleteHead();
    void deleteNodeInBetween(int);
    void deleteTail();
    void display();
};
// void function-name(node* &head)

void LinkedList::inserAtBegining(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        // if list is empty then make first node
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void LinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void LinkedList::insertAfterNode(int afterWhichNode, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);

    while (temp->next != NULL)
    {
        if (temp->data == afterWhichNode)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::deleteHead()
{
    Node *temp = head;
    head = head->next;
    delete (temp);
}
void LinkedList::deleteTail()
{
    Node *temp = head;
    Node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    // now temp contains tail and prev contains tail->prev
    prev->next = NULL;
    delete temp;
}
void LinkedList::deleteNodeInBetween(int key)
{
    // Store head node
    Node *temp = head;
    Node *prev = NULL;
    while (temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
}

void LinkedList::display()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList *l1 = new LinkedList();
    l1->inserAtBegining(10);
    l1->inserAtBegining(20);
    l1->inserAtBegining(30);
    cout << "Insert at begining" << endl;
    l1->display();

    l1->insertAtEnd(90);
    l1->insertAtEnd(100);
    cout << "Insert at the End" << endl;
    l1->display();

    cout << "Insert after a node" << endl;
    l1->insertAfterNode(10, 80);
    l1->display();

    cout << "After deleting head: " << endl;
    l1->deleteHead();
    l1->display();

    l1->deleteNodeInBetween(80);
    cout << "After deleting node 80" << endl;
    l1->display();

    cout << "After deleting tail: " << endl;
    l1->deleteTail();
    l1->display();

    return 0;
}