#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str = "()(())((()()))";
    int result = 0;
    int openbrack = 0;
    for (auto x : str)
    {
        if (x == '(')
        {
            openbrack++;
        }
        else if (x == ')')
        {
            openbrack--;
        }
        result = max(result, openbrack);
    }
    cout << result;
}