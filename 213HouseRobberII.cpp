class Solution {
    int rob2(vector<int>&nums, int start, int end) {
        int max_rob = 0;
        int prev = nums[start];
        int prev_2 = nums[start+1];
        int cur = nums[start] + nums[start+2];
        max_rob = max(cur, prev_2);
        int tmp;
        for(int i = start+3;i<end;i++){
           tmp = max(prev, prev_2);
           prev = prev_2;
           prev_2 = cur;
           cur = tmp+nums[i];
           if(cur>max_rob)
                max_rob = cur;
        }
        return max_rob;
    }
public:
    int rob(vector<int>& nums) {
        int n_size = nums.size();
        if(n_size==1)
            return nums[0];
        if(n_size==2){
            return max(nums[0],nums[1]);
        }
        int max_rob = 0;
        if(n_size==3){
            for(int n: nums){
                if (n > max_rob)
                    max_rob = n;
            }
            return max_rob;
        }
        max_rob = rob2(nums, 1, nums.size());
        
        int max_rob2 = rob2(nums, 0, nums.size()-1);
        return max(max_rob, max_rob2);
    }
};
