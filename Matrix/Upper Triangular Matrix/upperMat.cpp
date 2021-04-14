#include <iostream>
using namespace std;

#define size 3

bool checkUpperMat(int arr[size][size])
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int A[size][size] = {{1, 4, 5},
                         {0, 2, 6},
                         {0, 0, 3}};

    if (checkUpperMat(A))
    {
        cout << "The entered array is a Upper Triangular matrix.\n " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << A[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "Not a Upper Triangular Matrix" << endl;
    }

    return 0;
}