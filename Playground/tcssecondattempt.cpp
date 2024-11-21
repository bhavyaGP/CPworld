#include <bits/stdc++.h>
using namespace std;
int main()
{

    // median --
    //          N even->(arr(n/2) +arr(n/2+1))/2
    //          N odd  -> n+1/2

    // mode -- highest frequent element

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n)); // Resize the arr vector to have n rows and n columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int minMedian = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int median = 0;
        sort(arr[i].begin(), arr[i].end());
        if (n % 2 == 0)
        {
            median = (arr[i][n / 2] + arr[i][n / 2 - 1]) / 2;
        }
        else
        {
            median = arr[i][n / 2];
        }
        minMedian = min(median, minMedian);
    }
    std::cout << minMedian;
}