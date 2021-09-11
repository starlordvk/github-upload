#include <bits/stdc++.h>

using namespace std;

stack<int> sortStack(stack<int> s1)
{
    stack<int> s2;

    while (!s1.empty())
    {   
        int val = s1.top();
        s1.pop();

        while (!s2.empty() && s2.top() < val)
        {
            s1.push(s2.top());
            s2.pop();
        }

        s2.push(val);
    }
    return s2;
}


int main()
{
    stack<int> s1;
    s1.push(6);
    s1.push(7);
    s1.push(5);
    s1.push(4);
    s1.push(8);
    s1.push(2);
    s1.push(1);
    s1.push(3);

    stack<int> s2 = sortStack(s1);

    cout<<"Sorted stack is = ";
    while (!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop(); 
    }
    return 0;
}