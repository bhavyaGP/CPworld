#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long number = n, reversed = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reversed = (reversed * 10) + digit;
        n /= 10;
    }
    cout<< (number == reversed);
}