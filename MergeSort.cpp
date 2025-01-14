#include <iostream>
#include <vector>
#include <algorithm>

void Merge(std::vector<int> &inArr, int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex + 1 - leftIndex;
    int rightArraySize = rightIndex - midIndex;

    std::vector<int> leftArray(leftArraySize), rightArray(rightArraySize);

    int index = 0;
    std::for_each(leftArray.begin(), leftArray.end(), [&index, &inArr, leftIndex](int &element)
                  { element = inArr[leftIndex + index]; 
                  index++;
                  std::cout<<element<<" "; });
    index = 0;
    std::for_each(rightArray.begin(), rightArray.end(), [&index, &inArr, midIndex](int &element)
                  { element = inArr[midIndex + 1 + index]; 
                  index++;
                  std::cout<<element<< " "; });

    int i = 0, j = 0, k = leftIndex;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] > rightArray[j])
        {
            inArr[k] = rightArray[j];
            j++;
        }
        else
        {
            inArr[k] = leftArray[i];
            i++;
        }
        k++;
    }

    while (i < leftArraySize)
    {
        inArr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightArraySize)
    {
        inArr[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int> &inArr, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return;
    }
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    MergeSort(inArr, leftIndex, midIndex);
    MergeSort(inArr, midIndex + 1, rightIndex);
    Merge(inArr, leftIndex, midIndex, rightIndex);
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {9, 3, 6, 2, 8, 2, 5, 8};
    MergeSort(arr, 0, arr.size() - 1);

    std::for_each(arr.begin(), arr.end(), [](int x)
                  { std::cout << x << " "; });
    return 0;
}