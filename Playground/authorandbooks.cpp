#include <bits/stdc++.h>
using namespace std;

vector<string> arrangeAuthors(vector<vector<string>> &s)
{
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            if (j == 0)
            {
                ans.push_back(to_string(i + 1) + ". " + s[i][j]);
            }
            else
            {
                string bookname = string(1, 'A' + (j - 1)) + ". " + s[i][j];
                ans.push_back(bookname);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> s = {
        {"ChetanBhagat", "TwoStates", "Revolution", "HalfGirlfriend", "OneIndianGirl"},
        {"JKRowling", "HarryPotter", "FantasticBeasts"},
        {"JeffreyArcher", "OldLove", "FalseImpression"}};

    vector<string> ans = arrangeAuthors(s);
    for (auto a : ans)
    {
        cout << a << endl;
    }
    return 0;
}
