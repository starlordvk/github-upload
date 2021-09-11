#include <bits/stdc++.h>

using namespace std;

int power_of_2(int n)
{
    if (n == 1) 
    {   
        cout<<"1"<<"\n";
        return 1;
    }
    else
    {
        int curr = power_of_2(n/2) * 2;
        cout<<curr<<"\n";
        return curr;
    }
}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
    power_of_2(n);
}