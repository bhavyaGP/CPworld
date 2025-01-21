#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {9};
    vector<int> brr = {-9};
    long long k = 29;
    
    // First calculate cost without any rearrangement
    long long costWithoutRearrange = 0;
    for(int i = 0; i < arr.size(); i++) {
        costWithoutRearrange += abs(arr[i] - brr[i]);
    }
    
    // Calculate cost with rearrangement
    vector<int> sortedArr = arr;
    vector<int> sortedBrr = brr;
    sort(sortedArr.begin(), sortedArr.end());
    sort(sortedBrr.begin(), sortedBrr.end());
    
    long long costWithRearrange = 0;
    for(int i = 0; i < arr.size(); i++) {
        costWithRearrange += abs(sortedArr[i] - sortedBrr[i]);
    }
    costWithRearrange += k;  // Add the rearrangement cost
    
    // Take minimum of both approaches
    long long ans = min(costWithoutRearrange, costWithRearrange);
    
    cout << ans;
    return 0;
}