#include <iostream>
#include <bits/stdc++.h>

void InsertionSort(std::vector<int> &vec)
{
    int vectorSize = vec.size();
    for (int i = 1; i < vectorSize; i++)
    {
        int j = i-1;
        int v = vec[i];

        while(j >= 0 && vec[j] > v)
        {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = v;
    }
}

void Print(std::vector<int> vec)
{
    for(int x : vec)
    {
        std::cout<<x<<" ";
    }
    std::cout<<'\n';
}

int main()
{
    std::vector<int> arr = {2,1,5,3,7,5,4,6};
    InsertionSort(arr);
    Print(arr);
    return 0;
}