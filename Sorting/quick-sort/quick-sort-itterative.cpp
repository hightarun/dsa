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

void quickSortIterative(int arr[], int low, int high)
{
    int stack[high - low + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition_mid(arr, low, high); // change the partition function to partition_low/mid/high/rand to change the starting pivot position

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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
    quickSortIterative(arr, 0, n - 1);
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
