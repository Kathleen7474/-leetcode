class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = -buy;
        cout<<profit<<endl;
        for(int i = 0;i<prices.size();i++){
            if (prices[i]<buy){
                buy = prices[i];
            }
            if(prices[i]-buy>profit){
                profit = prices[i]-buy;
            }
            // cout<<buy<<" "<<profit<<endl;
        }
        return profit;
    }
};
