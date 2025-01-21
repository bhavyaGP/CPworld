#include <bits/stdc++.h>
using namespace std;
int findswpas(vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 != i)
        {
            swap(arr[arr[i] - 1], arr[i]);
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {2, 3, 1, 4};
    int n = arr.size();
    // count min swaps to convert arr to good array
    int count = findswpas(arr);
    cout << count << endl;

    return 0;
}