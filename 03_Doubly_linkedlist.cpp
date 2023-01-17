#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *head;
    Node *tail;

    Node()
    {
        next = prev = head = tail = NULL;
    }

    void createNode(int val)
    {
        // create a temp node
        Node *node = new Node();

        if (head == NULL && tail == NULL)
        {
            // Create 1st node in doubly linked list
            node->data = val;
            node->next = NULL;
            node->prev = NULL;
            head = tail = node;
        }
        else
        {
            node->data = val;
            node->next = NULL;
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void printForward()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printBackward()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void deleteHead()
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    void deleteInBetweenNodes(int val)
    {
        Node *temp = head;
        while (temp->data != val)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete (temp);
    }
    void deleteTail(){
        // as we have tail in our program we can simply delete tail using tail but we have to do it raw
        Node *temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->prev->next = nullptr;
        delete(temp);
    }
};

int main()
{
    Node node;
    node.createNode(5);
    node.createNode(10);
    node.createNode(15);
    node.createNode(25);
    node.createNode(83);
    node.createNode(75);
    node.createNode(65);

    node.printForward();

    node.deleteHead();
    cout<<"AFter deleting head"<<endl;
    node.printForward();

    node.deleteInBetweenNodes(25);
    cout<<"AFter deleting node in between i.e. 25"<<endl;
    node.printForward();

    node.deleteTail();
    cout<<"AFter deleting tail"<<endl;
    node.printForward();


    return 0;
}