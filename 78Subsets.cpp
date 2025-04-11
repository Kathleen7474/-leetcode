class Solution {
    vector<vector<int>> output;
    vector<int> tmp = {};
    // unordered_map<int, int> map;
    void subset2(int idx, vector<int>& nums){
        tmp.push_back(nums[idx]);
        output.push_back(tmp);
        // map[nums[idx]]--;
        for(int i = idx+1;i<nums.size(); i++){
            subset2(i, nums);
            // map[nums[i]] = 0;
        }
        tmp.pop_back();
        // map[idx]++;
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        output.push_back(tmp);
        for(int i = 0;i<nums.size(); i++){
            subset2(i, nums);
        }
        return output;
    }
};
