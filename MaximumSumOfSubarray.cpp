#include <iostream>
#include <algorithm>

// [-1, 2, 4, -3, 5, 2, -5, 2] find the maximum sum of subarray

int main()
{
    int n[8] = {-1, 2, 4, -3, 5, 3, -5, 2};
    int best = 0;

    // O(n^3) approach 1
    /*
    for (int i = 0; i < 8; i++) // starting element of subarray
    {
        int sum = 0;
        for (int j = i; j < 8; j++) // ending element of the subarray
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += n[k];
            }
            best = std::max(best, sum);
            std::cout << sum << std::endl;
        }
    }*/

    // O(n^2) approach 2
    /*
    for (int i = 0; i < 8; i++)
    {
        int sum = 0;
        for (int j = i; j < 8; j++)
        {
            sum += n[j];
            best = std::max(best, sum);
        }
    }*/

    // O(n) approach 3 Kadane's algorithm
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = std::max(n[i], sum + n[i]);
        best = std::max(best, sum);
    }

    std::cout << "Highest subarray sum: " << best << "\n";

    return 0;
}
