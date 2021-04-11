#include <iostream>

using namespace std;

// n(n+1)/2

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int main()
{
    cout << sum(10);

    return 0;
}