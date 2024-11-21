#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> k;
    // 3 1 2 6 9 4
    vector<int> vis(n, 0);
    vector<pair<int, int>> vp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = v[i] + v[j];
            if (vis[i] == 0 && vis[j] == 0 && sum % k == 0)
            {
                vis[i] = 1;
                vis[j] = 1;
                vp.push_back({v[i], v[j]});
            }
        }
    }
    for (auto a : vp)
    {
        cout << "(" << a.first << "," << a.second << ")" << endl;
    }
}