#include <iostream>

using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int c(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - 3);
    return t1 / (t2 * t3);
}

// recursive nCr formula made by analyzing pascals triangle
int cr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return cr(n - 1, r - 1) + cr(n - 1, r);
    }
}

int main()
{
    cout << cr(5, 3);

    return 0;
}