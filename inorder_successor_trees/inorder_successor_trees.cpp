#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    Node * left, * right;
    
    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key)
{
    if (root == nullptr) 
    {
        Node * newNode = new Node(key);
        return newNode;
    }

    if (key < root->data) 
    {
        root->left = insert(root->left, key);
    }

    else 
    {
        root->right = insert(root->right, key);
    }
 
    return root;
}

// Find minimum in a given subtree.
Node* findMinimum(Node* root)
{
    while(root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node* findMaximum(Node* root)
{
    while(root->right != nullptr)
    {
        root = root->right;
    }

    return root;
}

void findInOrderSuccessorRecursive(Node* root, Node*& succ, int key)
{
    if (root == nullptr)
    {
        succ = nullptr;
        return;
    }

    if (root->data == key)
    {
        if(root->right != nullptr)
        {
            succ = findMinimum(root->right);
        }
       
    } 
    else if (key < root->data)
    {
        succ = root;
        findInOrderSuccessorRecursive(root->left, succ, key);
    }
    else
    {
        findInOrderSuccessorRecursive(root->right, succ, key);
    }
}

Node* findInOrderSuccessorIterative(Node* root, int key)
{
    Node* succ = nullptr;
 
    while (1)
    {
        if (key < root->data)
        {   
            succ = root;
            root = root->left;
        }
 
        else if (key > root->data) 
        {
            root = root->right;
        }
 
        else 
        {
            if (root->right) 
            {
                succ = findMinimum(root->right);
            }
            break;
        }
 
        if (!root) 
        {
            return nullptr;
        }
    }

    return succ;
}

void InorderPredecessorRecursive(Node *root, Node *&pre, int key)
{
    if(root == NULL)
    {
        pre = nullptr;
        return;
    }

    if (key < root->data)
    {
        InorderPredecessorRecursive(root->left, pre, key);
    }
    else if (key > root->data)
    {   
        pre = root;
        InorderPredecessorRecursive(root->right, pre, key);
    }
    else
    {
        if (root->left)
        {
            pre = findMaximum(root->left);
        }
    }
}

int main()
{
        int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // find inorder successor for each key recursively
    for (int key: keys)
    {
        Node* prec = nullptr;
        findInOrderSuccessorRecursive(root, prec, key);
 
        if (prec != nullptr) {
            cout << "The successor of node " << key << " is " << prec->data;
        }
        else {
            cout << "The successor doesn't exist for " << key;
        }
 
        cout << endl;
    }

    // find inorder successor for each key iteratively
    for (int key: keys)
    {
        Node* prec = findInOrderSuccessorIterative(root, key);
 
        if (prec != nullptr) {
            cout << "The successor of node " << key << " is " << prec->data;
        }
        else {
            cout << "The successor doesn't exist for " << key;
        }
 
        cout << endl;
    }

    // find inorder predecessor for each key recursively
    for (int key: keys)
    {
        Node* prec = nullptr;
        InorderPredecessorRecursive(root, prec, key);
 
        if (prec != nullptr) {
            cout << "The predecessor of node " << key << " is " << prec->data;
        }
        else {
            cout << "The predecessor doesn't exist for " << key;
        }
 
        cout << endl;
    }
 
    return 0;
}