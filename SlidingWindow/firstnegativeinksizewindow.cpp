#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    int i = 0, j = 0;

    vector<int> ans;
    vector<int> neg;

    while (j < arr.size())
    {
        if (arr[j] < 0)
        {
            neg.push_back(arr[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (!neg.empty())
            {
                ans.push_back(neg[0]);
            }
            else
            {
                ans.push_back(0);
            }

            if (!neg.empty() && arr[i] == neg[0])
            {
                neg.erase(neg.begin());
            }

            i++;
            j++;
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
