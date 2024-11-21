#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <string>
int slotScore(string &original, string &guess)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (original[i] == guess[i])
        {
            ans += 2;
            original[i] = '#';
            guess[i] = '#';
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (guess[i] != '#')
        {
            for (int j = 0; j < 4; j++)
            {
                if (original[j] == guess[i])
                {
                    ans += 1;
                    original[j] = '#';
                    break;
                }
            }
        }
    }

    return ans;
}
int main()
{
    string original = "RGBY";
    string guess = "GGRR";
    cout << endl;
    cout << slotScore(original, guess);
}