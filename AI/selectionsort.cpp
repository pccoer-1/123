#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};
    int i, j, min, temp;

    cout << "Original Array:\n";
    
    for(i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    // Selection Sort
    for(i = 0; i < 4; i++)
    {
        min = i;

        for(j = i + 1; j < 5; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        // Swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "\nSorted Array:\n";

    for(i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}