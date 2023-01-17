#include <bits/stdc++.h>
using namespace std;

// ! Stack using array->
// ! https://www.tutorialspoint.com/cplusplus-program-to-implement-stack-using-array

class Node
{
public:
    int value;
    Node *next;

    Node()
    {
        value = 0;
        next = NULL;
    }
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    void push(int);
    void pop();
    // void peek(int);
    bool isEmpty();
    // bool isFull();
    void display();
};

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}
void Stack::pop()
{
    Node *temp;
    if (isEmpty())
    {
        cout << "Stack Underflow empty" << endl;
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty()
{
    return top == NULL;
}

void Stack::display()
{
    Node *temp = new Node();
    temp = top;
    if (top == NULL)
        cout << "Stack is empty";
    else
    {
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Stack s1;
    s1.push(40);
    s1.push(90);
    s1.push(29);
    s1.pop();
    s1.display();
    return 0;
}