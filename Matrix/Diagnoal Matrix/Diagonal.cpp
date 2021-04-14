#include <iostream>
using namespace std;

#define size 3

bool checkDiagonal(int arr[size][size])
{
    bool flag = true;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                if (arr[i][j] == 0)
                    flag = false;
            }
            else
            {
                if (arr[i][j] != 0)
                    flag = false;
            }
        }
    }

    return flag;
}

int main()
{
    int A[size][size] = {{1, 0, 0},
                         {0, 2, 0},
                         {0, 0, 3}};

    if (checkDiagonal(A))
    {
        cout << "The entered array is a diagonal matrix.\n " << endl;
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
        cout << "Not a diagonal Matrix" << endl;
    }

    return 0;
}