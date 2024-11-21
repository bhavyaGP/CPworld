#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // 2 3 -2 4
    // int result = 0;
    // int maxEnding = v[0];
    // for (int i = 0; i < v.size(); i++)
    // {
    //     maxEnding = max(maxEnding + v[i], v[i]);
    //     result = max(result, maxEnding);
    // }
    // cout << result;

    int product = 1;
    int ans = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        product = product * v[i];
        ans = max(ans, product);
    }
    cout << ans;
}