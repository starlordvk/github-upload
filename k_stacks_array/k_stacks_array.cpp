#include <bits/stdc++.h>

using namespace std;

class kstacks
{
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:

    kstacks(int n1, int k1) : n(n1), k(k1) 
    {
        arr = new int[n]{0};
        top = new int[k]{-1};
        next = new int[n];
        for (int i = 0; i < n-1; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        free = 0;
    }

    void push(int val, int stack_num)
    {
        if(isFull()) 
        {
            cout<<"stack full\n";
            return;
        }
        int i = free;
        free = next[i];
        next[i] = top[stack_num];
        top[stack_num] = i;
        arr[i] = val;

    }

    int pop(int stack_num)
    {
        if(isEmpty(stack_num))
        {
            cout<<"Stack Empty\n";
            return INT_MAX;
        }

        int i = top[stack_num];
        top[stack_num] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }

    bool isFull()
    {
        return (free == -1);
    }

    bool isEmpty(int stack_num)
    {
        return (top[stack_num] == -1);
    }

    void displayStack(int stack_num)
    {   
        cout<<"Displaying stack "<<stack_num<<" = ";
        if (isEmpty(stack_num)) 
        {
            cout<<"Stack empty\n";
            return;
        }

        int i = top[stack_num];
        while(i != -1)
        {
            cout<<arr[i]<<" ";
            i = next[i];
        } 
        cout<<"\n";
    }
};

int main()
{
    kstacks kStacks(10,3);
    kStacks.push(5,0);
    kStacks.push(7,0);
    kStacks.push(4,1);
    //kStacks.push(9,2);
    //kStacks.push(6,1);
    kStacks.displayStack(0);
    kStacks.displayStack(1);
    kStacks.displayStack(2);
    
    return 0;
}