#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> nums = {4, 4, 4};
    int k = 3;
    int low = 0, high = 0, windowsize = k;
    long long result = 0;
    unordered_set<int> st;
    long long sum = 0;
    while(high < nums.size()){

        if(st.find(nums[high]) == st.end()){
            sum += nums[high];
            st.insert(nums[high]);
            if(high - low + 1 == windowsize){
                result = max(result, sum);
                sum -= nums[low];
                st.erase(nums[low]);
                low++;
            }
            high++;
        }else{
            sum -= nums[low];
            st.erase(nums[low]);
            low++;
        }
    }
    cout << result << endl;
}