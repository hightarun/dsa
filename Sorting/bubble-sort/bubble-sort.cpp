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

// BUBBLE SORT
void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isSwapped = false; //flag to detect swap

        for (int j = 0; j < size - i - 1; j++) // in every loop , the last element will be at its sorted position
        {
            //when the current item is bigger than next
            if (array[j] > array[j + 1])
            {
                swaps(array[j], array[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break; // No swap means array is now sorted so breaking out of outer loop
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
    bubbleSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}