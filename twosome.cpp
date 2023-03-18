class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        int sum = 0;
        vector<int> output;
        for (int i = 0;i<length;i++){
            output.clear();

            sum = nums[i];
            output.push_back(i);
            for(int j = i+1;j<length;j++){
                sum = sum + nums[j];
                if(sum==target){
                    output.push_back(j);
                    return output;
                }
                sum-=nums[j];
            }
        }
       return output; 
    }
};
