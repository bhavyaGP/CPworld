#include <bits/stdc++.h>
using namespace std;
void getindex(vector<int> arr)
{
    vector<int> temp = arr;
    vector<int> ans(2, -1);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != temp[i])
        {
            ans[0] = i;
        }
        if (arr[arr.size() - 1 - i] != temp[arr.size() - 1 - i])
        {
            ans[1] = arr.size() - 1 - i;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    getindex(arr);
}
