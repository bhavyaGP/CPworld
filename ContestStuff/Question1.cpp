//You are given a string s consisting only of digits. A valid pair is defined as two adjacent digits in s such that:
// The first digit is not equal to the second.
// Each digit in the pair appears in s exactly as many times as its numeric value.
// Return the first valid pair found in the string s when traversing from left to right. If no valid pair exists, return an empty string.©leetcode

#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
    unordered_map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    for (int i = 0; i < s.length() - 1; i++) { 
        if (s[i] != s[i + 1]) {
            if (mp[s[i]] == (s[i] - '0') && mp[s[i + 1]] == (s[i + 1] - '0')) {
                return string(1, s[i]) + string(1, s[i + 1]); 
            }
        }
    }
    return "";
}
int main()
{
    string s = "2523533";
    string ans = solve(s);
    cout << ans << endl;
}