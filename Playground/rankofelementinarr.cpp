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

    unordered_map<int, int> mp;
    set<int> st(begin(arr), end(arr)); 

    int rank = 1;
    for (auto x : st)
    {
        mp[x] = rank; 
        rank++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = mp[arr[i]]; 
    }

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
