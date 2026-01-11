#include <iostream>
#include <algorithm>
using namespace std;

// sorting fixed array
void swap(int &x, int &y);
void bubbleSort(int A[], int n);
void printArr(int A[], int n);
int main()
{
    int arr[] = {8, 5, 7, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]); //(6 * 4) / 4 = 6
    cout << "Array Elements before sorting: ";
    printArr(arr, n);
    cout << "Array Elements after sorting: ";
    bubbleSort(arr, n);
    printArr(arr,n); 

    return 0;
}

void bubbleSort(int A[], int n)
{
    int swapped = 0, c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 -i; j++)
        {
            if(A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                swapped = 1;
            }
            c++;
        }
        if (swapped == 0)
            break;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}