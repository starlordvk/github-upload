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

Node* sortedArrayToBST(int arr[], int start, int end)
{
    if (end < start) return NULL;
    
    int mid = (end + start)/2;

    Node * root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{   
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);

    return 0;
}