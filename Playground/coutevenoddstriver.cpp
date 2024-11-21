#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    for (auto x : arr)
    {
        m[x]++;
    }
    int odd = 0, even = 0;
    for (auto x : m)
    {
        if (x.second % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    cout << odd << " " << even << endl;
}
int main()
{
    vector<int> arr = {5 ,2 ,9, 9, 7 ,5, 1 ,3};
    rotate(arr,arr.size());
}