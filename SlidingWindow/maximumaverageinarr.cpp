#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    int n = nums.size();
    double ans = INT_MIN;
    double sum = 0;
    int windowsize = k, low = 0, high = 0;
    while (high < n)
    {
        sum += nums[high];
        if (high - low + 1 == windowsize)
        {
            ans = max(ans, sum / windowsize);
            sum -= nums[low];
            low++;
        }
        high++;
    }
    cout << ans;
}