#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    string str = to_string(num);
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

int countPalindromePairs(vector<int>& v)
{
    int count = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int result = v[i] ^ v[j];

            if (isPalindrome(result))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int result = countPalindromePairs(v);
        cout << result << endl;
    }
    return 0;
}