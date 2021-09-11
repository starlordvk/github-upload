#include <bits/stdc++.h>

using namespace std;

int fibonacci_memorisation(int n, int memo[])
{
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else if (memo[n] > 0) return memo[n];

    memo[n] = fibonacci_memorisation(n-1, memo) + fibonacci_memorisation(n-2, memo);
    return memo[n];
}

int main()
{
    int n;
    cout<<"Enter N";
    cin>>n;
    int * memo = new int[n+1]{0};
    
    for (int i = 0; i <n ; i++)
    {
        cout<<i<<"th = "<<fibonacci_memorisation(i, memo)<<"\n";
    }
}