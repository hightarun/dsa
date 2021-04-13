#include <iostream>

using namespace std;

void toh(int n, int A, int B, int C)
{
    if (n > 0)
    {
        toh(n - 1, A, C, B);
        cout << "Move disk from " << A << " to " << C << endl;
        toh(n - 1, B, A, C);
    }
}

int main()
{
    toh(3, 1, 2, 3);
}