/*

*****
 ***
  *
*/

#include <iostream>
using namespace std;

int main()
{
    int rows = 5;
    int maxStars = rows * 2 - 1;

    for (int i = rows; i >= 1; i--)
    {
        for (int j = rows; j >= i; j--)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}