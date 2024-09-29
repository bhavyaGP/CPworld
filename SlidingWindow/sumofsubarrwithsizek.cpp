#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int k = 3;
    int start = 0, end = 0;
    int sum = 0;
    vector<int> sums;
    while (end < arr.size())
    {
        sum += arr[end];
        if (end - start + 1 < k)
        {
            end++;
        }
        else
        {
            sums.push_back(sum);
        }
        sum -= arr[start];
        start++;
        end++;
    }
    for(auto x:sums){
        cout<<x<<" "; 
    }
}