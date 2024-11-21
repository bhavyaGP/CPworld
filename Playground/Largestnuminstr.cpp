#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string num = "4602";
    int n = stoi(num);
    int size = (log10(stod(num)) + 1);
    int oddest = INT_MIN;
    while (size > 0)
    {
        if ((n % 10) % 2 != 0)
        {
            oddest = max(n % 10, oddest);
        }
        n = n / 10;
        size--;
    }
    if (oddest != INT_MIN)
    {
        cout << to_string(oddest);
    }
    cout << "";
}