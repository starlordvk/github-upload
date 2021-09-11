#include <bits/stdc++.h>

using namespace std;

template <class value>
class myStack
{
    struct stackNode
    {
        value v;
        stackNode *next;

        stackNode(value val)
        {
            v = val;
            next = NULL;
        }
    };

    stackNode *top;
    int cap;

public:

    myStack()
    {   
        top = NULL;
    }
    
    void push(value v)
    {
        stackNode *newNode = new stackNode(v);
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout<<"stack empty\n";
            return;
        }
        stackNode * newNode = top;
        top = top->next;
        cout<<"Deleted "<<newNode->v<<"\n";
        delete newNode;
    }
    
    bool isEmpty()
    {
        if (top == NULL) return true;
        else return false;
    }

    void print()
    {
        stackNode *newNode = top;
        while (newNode != NULL)
        {
            cout<<newNode->v<<" ";
            newNode = newNode->next;
        }
        cout<<"\n";
    }

    ~myStack()
    {
        stackNode *newNode = top;
        stackNode *temp;
        while (newNode != NULL)
        {
            temp = newNode;
            newNode = newNode->next;
            delete temp;
        }
    }
};

int main()

{
    myStack<int> s ;
    s.push(5);
    s.push(9);
    s.push(12);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}