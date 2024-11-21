#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumOfTwoSmallest(const vector<int> &A)
{
    int n = A.size();
    int ans = INT_MIN; // Initialize ans to a very small value

    for (int start = 0; start <= n - 2; ++start)
    {
        int smallest = A[start];
        int secondSmallest = INT_MAX;

        for (int end = start + 1; end < n; ++end)
        {
            if (A[end] < smallest)
            {
                secondSmallest = smallest;
                smallest = A[end];
            }
            else if (A[end] < secondSmallest)
            {
                secondSmallest = A[end];
            }

            if (secondSmallest != INT_MAX)
            {
                ans = max(ans, smallest + secondSmallest);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> A = {3, 8};
    int result = maxSumOfTwoSmallest(A);
    cout << "Maximum sum of the two smallest elements in any subarray: " << result << endl;
    return 0;
}
