#include <bits/stdc++.h>
using namespace std;
int main()
{

    int num;
    cin >> num;
    int sum = 0;
    while (num > 9)
    {
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        sum = 0;
    }
    cout << num;
}