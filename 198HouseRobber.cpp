class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> robbed(nums.size(),0);
        robbed[0] = nums[0];
        if (nums.size()==1){
            return nums[0];
        }
        robbed[1] = nums[1];
        if (nums.size()==2){
            return max(nums[0], nums[1]);
        }
        robbed[2] = nums[0]+ nums[2];
        for(int i = 3; i<nums.size();i++){
            robbed[i] = max(robbed[i-2], robbed[i-3]);
            robbed[i] = robbed[i]+nums[i];
        }
        return max(robbed[nums.size()-1],robbed[nums.size()-2]);
    }
};
