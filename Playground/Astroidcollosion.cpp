#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (!s.empty() && s.top() > 0 && x < 0)
        {
            int sum = s.top() + x;
            if (sum < 0)
            {
                s.pop();
            }
            else if (sum > 0)
            {
                x = 0;
            }
            else
            {
                s.pop();
                x = 0;
            }
        }
        if (x!=0)
        {
            s.push(x);
        }
    }

    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
}
