#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "leetcode";
    int k = 2;
    string num = "";

    for (char &ch : s)
    {
        int char_int = ch - 'a' + 1; // a : 1, b : 2 and so on...
        num += to_string(char_int);
    }

    int sum = 0;

    while (k--)
    {
        sum = 0;
        for (char &ch : num)
        {
            sum += ch - '0';
        }

        num = to_string(sum);
    }
    cout << stoi(num);
}
