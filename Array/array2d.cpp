#include <iostream>

using namespace std;

int main()
{
    int arr[3][3], i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "Enter element";
            cin >> arr[i][j];
        }
    }
    printf("\n printing the elements ....\n");
    for (i = 0; i < 3; i++)
    {
        cout << endl;
        for (j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j];
        }
    }
}