#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // 10, 5, 2, 7, 1, 9  k=15

    int maxi = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                maxi = max(maxi, j - i + 1);
            }
        }
    }
    cout << maxi;
}