/*
*
**
***
****
***
**
*
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int rows = 5;
    for (int i = rows; i >= -rows; i--)
    {
        for (int j = rows; j >= abs(i); j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}