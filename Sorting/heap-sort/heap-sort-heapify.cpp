#include <iostream>
#include <ctime>   // for time
#include <iomanip> // for setPrecision

using namespace std;

void heapify(int arr[], int n, int i);
void swap(int *a, int *b);
void display(int arr[], int size);

void heapSort(int arr[], int n)
{
    // loop to create max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Max Heapified  ";
    display(arr, n); //displaying array after heapifying

    //loop to sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]); // swapping last element with first element
        // cout << "Array after swapping";
        // display(arr, n);
        heapify(arr, i, 0);
        // cout << "Array after max-heapifying  ";
        // display(arr, n);
    }
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

    heapSort(arr, n);

    cout << "Array after Sorting: ";
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}