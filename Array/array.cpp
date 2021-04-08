#include <iostream>

using namespace std;

int summation(int arr[])
{
    int sum = 0, i;
    for (i = 0; i < 5; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int arr[5] = {0, 1, 2, 3, 4};
    cout << summation(arr); // address of array is passed when array is passed in function.

    return 0;
}
