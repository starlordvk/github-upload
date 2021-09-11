#include<bits/stdc++.h>

using namespace std;

class Number
{

public:
    // default constructor
    Number() 
    {
        val = 0;
    }

    //parameterized constructor
    Number(int x) : val(x) {}

    //Getter method
    int GetVal() const
    {
        return val;
    }

    //Setter Method
    void SetVal(int x)
    {
        val = x;
    }

    //Overloading operator '+'
    Number operator+(const Number& num2)
    {
        Number num;
        num.val = this->GetVal() + num2.GetVal();
        return num;
    }

private:
    //private data members
    int val;
};

int main()
{
    Number n1(5);
    Number n2(10); 
    Number n3(20);
    Number sum = n1 + n2 + n3;
    cout <<sum.GetVal();
    return 0;
}