class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // int a_sum = 0; b_sum = 0;
        int total_sum = 0;
        for(int n: nums){
            total_sum += n;
        }
        if (total_sum%2 != 0) return false;
        int half = total_sum/2;
        vector<bool> dp(half+1, false);
        dp[0] = true;
        for (int n: nums){
            for(int cur_sum = half; cur_sum>=n;cur_sum--){
                dp[cur_sum] = dp[cur_sum]||dp[cur_sum-n];
                if(dp[half]) return true;
            }
        }
        return dp[half];
    }
};
