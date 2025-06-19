class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> sort_nums = nums;
        sort(sort_nums.begin(), sort_nums.end());
        int max_len = 1, cur_len = 1;
        int last_val = sort_nums[0];
        for(int i = 1;i<nums.size();i++){
            // 注意同一個值的情形
            if(sort_nums[i]==last_val+1){
                cur_len++;
                if(cur_len>max_len)
                    max_len = cur_len;
                
            }else if(sort_nums[i]>last_val+1){
                cur_len = 1;
            }
            last_val = sort_nums[i];
        }
        return max_len;
    }
};
