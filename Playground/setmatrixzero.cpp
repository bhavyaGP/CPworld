#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = v.size();
    int m = v[0].size();

    vector<int> col(m, false);
    vector<int> row(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                col[i] = true;
                row[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[i] || row[j])
            {
                v[i][j] = 0;
            }
        }
    }

    for (auto it : v)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}