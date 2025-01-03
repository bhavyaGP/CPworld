#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k = 3;
    int threshold = 5;
    int n = arr.size();
    double sum = 0;
    int windowsize = k, low = 0, high = 0;
    int count = 0;
    while (high < n)
    {
        sum += arr[high];

        if (high - low + 1 == windowsize)
        {
            double avg = sum / windowsize;
            if (avg >= threshold)
            {
                count++;
            }
            sum -= arr[low];
            low++;
        }

        high++;
    }
    cout << count;
}