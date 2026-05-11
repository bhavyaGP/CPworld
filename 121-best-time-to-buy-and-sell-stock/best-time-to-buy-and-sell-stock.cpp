class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minPrice=prices[0]; //because we are assuming that first price is min
        int n=prices.size();
        for(int i=1;i<n;i++){
            int currprofit=prices[i]-minPrice;
            profit=max(profit,currprofit);  //current element se subarr start karu yaa last sum me add kardu 
            minPrice=min(prices[i],minPrice); // minPrice woh min hai ya curr hai woh min 
        }
        return profit;
    }
};