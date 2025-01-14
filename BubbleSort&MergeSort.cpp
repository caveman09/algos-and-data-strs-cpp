#include <iostream>
#include <vector>
#include <algorithm>

// [1,3,8,2,9,2,5,6] Sort

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left array
    int n2 = right - mid;    // size of right array

    std::vector<int> L(n1), R(n2);

    // initialize both arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    std::for_each(L.begin(), L.end(), [](int i)
                  { std::cout << i << " "; });
    std::cout << "   ";
    std::for_each(R.begin(), R.end(), [](int i)
                  { std::cout << i << " "; });

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
    std::cout << std::endl;
}

int main()
{
    std::vector<int> n = {1, 3, 8, 2, 9, 2, 5, 6};

    // O(n^2) bubble sort
    /*
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = i; j < n.size(); j++)
        {
            if (n[i] > n[j])
            {
                int temp = n[j];
                n[j] = n[i];
                n[i] = temp;
            }
        }
    }*/

    // O(nlogn) merge sort

    mergeSort(n, 0, n.size() - 1);

    std::for_each(n.begin(), n.end(), [](int i)
                  { std::cout << i << " "; });

    std::cout << "Sorted Array \n";
}
