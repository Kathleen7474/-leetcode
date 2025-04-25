class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> leftprod = nums;
        // vector<int> rightprod = nums;
        int leftprod = nums[0], rightprod = nums[nums.size()-1];
        vector<int> output(nums.size(),1);
        for(int i = 1;i<nums.size()-1;i++){
            if(i!=0&&i!=nums.size()-1){
                output[i] *= leftprod;
                output[nums.size()-1-i] *= rightprod;
            }
            leftprod = leftprod*nums[i];
            rightprod = rightprod*nums[nums.size()-1-i];
        }
        output[0] = rightprod;
        output[nums.size()-1] = leftprod;
        return output;
    }
};
