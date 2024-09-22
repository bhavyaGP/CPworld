#include <iostream>
#include <vector>
#include <algorithm> // Add this line to include the <algorithm> header
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin() + m + 1, arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}