class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        int sum = 0;
        while(right<nums.size()){
            int a = nums[right];
            sum = sum+a;
            // right++;
            while(sum>=target){
                if(right-left<len){
                    start = left;
                    len = right - left;
                }
                int b = nums[left];
                sum = sum - b;
                left++;
            }
            right++;
        } 
        if (len==INT_MAX)
            return 0;
        return len+1;
    }
};
