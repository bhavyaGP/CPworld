#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 1, 2, 3};

    vector<int> even, odd;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i & 1)
        {
            odd.push_back(arr[i]);
        }
        else
        {
            even.push_back(arr[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    int eveni = 0, oddj = 0, i = 0;
    while (i < arr.size())
    {
        if (i & 1)
        {
            arr[i++] = odd[oddj++];
        }
        else
        {
            arr[i++] = even[eveni++];
        }
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
}