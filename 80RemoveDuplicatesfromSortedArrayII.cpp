class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, cur = 0;
        for (int i = 0;i<nums.size();i++){
            if(nums[start]==nums[i]){
                if(cur-start<2){
                    nums[cur] = nums[i];
                    cur++;
                }
            }else{
                start = cur;
                cur++;
                nums[start] = nums[i];
            }
        }
        return cur;
    }
};
