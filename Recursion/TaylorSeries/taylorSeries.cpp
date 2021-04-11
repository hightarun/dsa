#include <iostream>

using namespace std;

int taylorSeries(int x, int n)
{
    static int p = 1, f = 1;
    int r;
    if (n == 0)
        return 1;
    else
    {
        r = taylorSeries(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int main()
{

    cout << taylorSeries(2, 3);
    return 0;
}