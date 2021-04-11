#include <iostream>

using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return power(a, b - 1) * a;
}

int main()
{
    cout << power(2, 3);

    return 0;
}
