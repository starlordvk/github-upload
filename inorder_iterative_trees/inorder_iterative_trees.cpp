#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    Node * left;
    Node * right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


void InOrderTraversalIterative(Node *root)
{
    if (root == NULL) return ;

    stack <Node *> s;
    Node * temp = root;
    
    while (temp != NULL ||  !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout<<temp->data<<" ";

        temp = temp->right;
    }
    
}

int main()
{
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    InOrderTraversalIterative(root);
    return 0;
}