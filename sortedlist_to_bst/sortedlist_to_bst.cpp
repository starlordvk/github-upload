#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int key)
    {
        data = key;
        next = nullptr;
    }
}

void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = new ListNode();
     
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int countLNodes(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

/* Function to print nodes in a given linked list */
void printList(ListNode *node)
{
    while(node!=NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

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

Node* sortedListToBST(int arr[], int start, int end)
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
    ListNode* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);

    Node *root = sortedListToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);

    return 0;
}