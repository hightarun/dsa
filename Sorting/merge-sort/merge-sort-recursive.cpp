#include <iostream>
#include <ctime>   // for time
#include <iomanip> // for setPrecision
using namespace std;

void merge(int[], int, int, int);

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return; //returns recursively
    }

    int mid = low + (high - low) / 2; // middle index of array

    mergeSort(arr, low, mid);      //Recursively call mergeSort on left subarray
    mergeSort(arr, mid + 1, high); //Recursively call mergeSort on right subarray
    merge(arr, low, mid, high);    //merge the left and the right subarray
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
    mergeSort(arr, 0, n - 1); //(n-1) for last index
    cout << "Array after Sorting: ";
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temp arrays
    int Left[n1], Right[n2];

    // Copy data to temp arrays Left[] and Right[]
    for (int i = 0; i < n1; i++)
        Left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    // Now we have to merge these 2 temp arrays back into arr[low..high]

    int i = 0, j = 0, k = low; // Initial index of first , second and merged subarray respectively

    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left[], if there are any
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right[], if there are any
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
