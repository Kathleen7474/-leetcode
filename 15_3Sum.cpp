class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n_size = nums.size();
        for(int i = 0;i<n_size;i++){
            if(i>0&&nums[i-1]==nums[i])
                continue;
            int l = i+1, r = n_size -1;
            int sum = 0;
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                if(sum<0){
                    l++;
                }else if(sum>0)
                    r--;
                else{
                    output.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(nums[l-1]==nums[l]&&l<r)
                        l++;
                    while(nums[r+1]==nums[r]&&l<r)
                        r--;
                }
            }
        }
        return output;
    }
};
