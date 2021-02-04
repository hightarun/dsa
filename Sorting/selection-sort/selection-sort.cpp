#include <iostream>
#include <ctime>   // for time
#include <iomanip> // for setPrecision
using namespace std;

void swaps(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *array, int size)
{
    int i, j, imin;
    for (i = 0; i < size - 1; i++)
    {
        imin = i;                      //get index of minimum data
        for (j = i + 1; j < size; j++) //to find minimum element in the unsorted part of the array and store it in imin
        {
            if (array[j] < array[imin])
            {
                imin = j;
            }
        }

        swaps(array[i], array[imin]); //placing in correct position in the sorted part of the array
    }
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    time_t start, end; //to measure time taken by program to execute

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    start = clock(); //recording the end time of program

    cout << "Array before Sorting: ";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}