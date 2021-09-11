#include <iostream>

int Gcd(int m, int n)
{
    if (n == 0) return m;
    while (n > 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int GcdRecursive(int m, int n)
{
    if (n == 0) return m;
    return GcdRecursive(n, m % n);
}

int main()
{
    std::cout<<"Hello World\n";
    std::cout<<"GCD = "<<Gcd(24,60)<<"\n";
    std::cout<<"GCD Recursive = "<<GcdRecursive(24,60)<<"\n";
    return 0;
}