#include <iostream>
#include <algorithm>
#include <vector>

// [6, 7, 8, 9, 1, 2, 3, 4, 5] , array was initially sorted in ascending order but then rotated about a random point, find the point of rotation.
// (index of the lowest element) complexity should be O(logn) -> Binary Search

int findRotationPoint(const std::vector<int> &inArr)
{
    int leftIndex = 0;
    int rightIndex = inArr.size() - 1;
    int midIndex = 0;

    int x = -1; // target index - smallest element index
    while (rightIndex > leftIndex)
    {
        midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if (inArr[midIndex] < inArr[rightIndex])
        {
            rightIndex = midIndex;
        }
        else
        {
            leftIndex = midIndex + 1;
        }
    }
    x = rightIndex;
    return x;
}

int main()
{
    std::vector<int> arr = {10, 20, 30, 40, 50, 5, 7};
    int point = findRotationPoint(arr);
    std::cout << "Rotation point : " << point << std::endl;
    return 0;
}