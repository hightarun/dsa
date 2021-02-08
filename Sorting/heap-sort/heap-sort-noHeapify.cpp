#include <iostream>
#include <ctime>   // for time
#include <iomanip> // for setPrecision

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Insert(int a[], int n)
{
    int i = n, temp;
    temp = a[i];
    while (i > 1 && temp > a[i / 2])
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

int Delete(int a[], int n)
{
    int i, j, del;
    del = a[1];
    a[1] = a[n];
    a[n] = del;
    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (a[j + 1] > a[j])
        {
            j = j + 1;
        }
        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return del;
}

int main()
{
    time_t start, end; //to measure time taken by program to execute

    // int n;
    // cout << "Enter the number of elements: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter elements:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    int n = 8;
    int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};

    start = clock(); //recording the end time of program

    cout << "Array before Sorting: ";
    display(arr, 8);

    for (int i = 2; i < n; i++)
    {
        Insert(arr, i);
    }

    for (int i = n - 1; i > 1; i--)
    {
        Delete(arr, i);
    }

    cout << "Array after Sorting: ";
    display(arr, n);

    end = clock(); //recording the end time of program

    // Calculating total time taken by the program after inputing array.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
