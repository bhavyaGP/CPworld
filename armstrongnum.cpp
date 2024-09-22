#include <bits/stdc++.h>
using namespace std;
int findsize(int n)
{
    return (int)(log10(n) + 1);
}
int main()
{
    int n;
    cin >> n;
    int size = findsize(n);
    int temp = n;
    int sum = 0;

    // 371

    while (temp != 0)
    {
        sum+=pow(temp%10,size);
        temp/=10;
    }
    cout<<(sum==n);
}