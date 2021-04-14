#include <iostream>
using namespace std;

#define size 3

bool checkLowerMat(int arr[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
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
    int A[size][size] = {{1, 0, 0},
                         {4, 2, 0},
                         {5, 6, 3}};

    if (checkLowerMat(A))
    {
        cout << "The entered array is a Lower Triangular matrix.\n " << endl;
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
        cout << "Not a Lower Triangular Matrix" << endl;
    }

    return 0;
}