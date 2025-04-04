class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_pos = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=nums[cur_pos]){
                cur_pos++;
                nums[cur_pos] = nums[i];
            }
        }
        return cur_pos+1;
    }
};
