#include <iostream>
#include <cstdlib> // for rand , srand
#include <ctime>   // for time
#include <iomanip> // for setPrecision
using namespace std;

void swap(int, int);
int partition_high(int[], int, int);
int partition_low(int[], int, int);
int partition_mid(int[], int, int);
int partition_rand(int[], int, int);

//quicksort algorithm
void quickSortRecursive(int arr[], int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition_rand(arr, low, high); // change the partition function to partition_low/mid/high/rand to change the starting pivot position

        //sort the sub arrays independently
        quickSortRecursive(arr, low, pivot - 1);
        quickSortRecursive(arr, pivot + 1, high);
    }
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
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
    cout << "Input array" << endl;
    display(arr, n);
    cout << endl;
    quickSortRecursive(arr, 0, n - 1);
    cout << "Array sorted with quick sort" << endl;
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using random element as pivot
int partition_rand(int arr[], int low, int high)
{
    srand(time(NULL));
    int start, end, random = low + rand() % (high - low);
    swap(&arr[low], &arr[random]);
    int pivot = arr[low];
    start = low;
    end = high + 1;

    do
    {
        // increment start
        do
        {
            start++;
        } while (arr[start] < pivot && start <= high);

        // decrement end
        do
        {
            end--;
        } while (arr[end] > pivot);

        if (start < end)
        {
            swap(&arr[start], &arr[end]); //swapping arr[start] with arr[end]
        }

    } while (start < end);

    //now we have to swap pivot element with arr[end] , after this pivot element is at its sorted position
    arr[low] = arr[end];
    arr[end] = pivot;

    return (end);
}

// partition the array using last element as pivot
int partition_high(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// partition the array using middle element as pivot
int partition_mid(int arr[], int low, int high)
{
    int start, end, mid = (low + high) / 2;
    swap(&arr[low], &arr[mid]);
    int pivot = arr[low];
    start = low;
    end = high + 1;

    do
    {
        // increment start
        do
        {
            start++;
        } while (arr[start] < pivot && start <= high);

        // decrement end
        do
        {
            end--;
        } while (arr[end] > pivot);

        if (start < end)
        {
            swap(&arr[start], &arr[end]); //swapping arr[start] with arr[end]
        }

    } while (start < end);

    //now we have to swap pivot element with arr[end] , after this pivot element is at its sorted position
    arr[low] = arr[end];
    arr[end] = pivot;

    return (end);
}

// partition the array using first element as pivot
int partition_low(int arr[], int low, int high)
{
    int start, end;
    int pivot = arr[low];
    start = low;
    end = high + 1;

    do
    {
        // increment start
        do
        {
            start++;
        } while (arr[start] < pivot && start <= high);

        // decrement end
        do
        {
            end--;
        } while (arr[end] > pivot);

        if (start < end)
        {
            swap(&arr[start], &arr[end]); //swapping arr[start] with arr[end]
        }

    } while (start < end);

    //now we have to swap pivot element with arr[end] , after this pivot element is at its sorted position
    arr[low] = arr[end];
    arr[end] = pivot;

    return (end);
}
