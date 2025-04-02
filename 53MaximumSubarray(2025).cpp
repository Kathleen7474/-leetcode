class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 包含自己的最佳解，紀錄從哪到此
        int max = INT_MIN;
        int prev = INT_MIN;
        for(auto n: nums){
            if(prev==INT_MIN){
                prev = n;
            }
            else if(n>prev+n){
                // best.push_back(n);
                prev = n;
            }
            else{
                // best.push_back(n+prev);
                prev = n+prev; 
            }
            if (prev>max)
                max = prev;
        }
        return max;
    }
};
