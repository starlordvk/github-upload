#include <iostream>

int Gcd(int m, int n)
{
    int t = std::min(m, n);
    while (t > 0)
    {
        if ((m % t != 0) || (n % t != 0))
        {
            t--;
        }
        else break;
    }
    return t;
}

int main()
{
    std::cout<<Gcd(24, 60)<<"\n";
    return 0;
}