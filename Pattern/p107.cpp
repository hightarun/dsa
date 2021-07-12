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
    int rows = 3;
    for (int i = rows; i >= -rows; i--)
    {
        for (int j = 1; j <= abs(i); j++)
        {
            cout << " ";
        }
        for (int k = rows; k >= abs(i); k--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}