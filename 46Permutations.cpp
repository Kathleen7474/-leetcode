class Solution {
    vector<vector<int>> output;
    vector<int> tmp;
    unordered_map<int, int> map;
    void permute2(int n, vector<int>& nums){
        tmp.push_back(n);
        map[n]--;
        int flag = false;
        // 找還有的
        for (const auto& [key, val] : map) {
            if (val != 0) {
                flag = true;
                // 找到一個非零的，就 break 或 return
                permute2(key, nums);
            }
        }
        if (!flag){
            output.push_back(tmp);
        }
        // 如果全部都為0了
        map[n]++;
        tmp.pop_back();
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        for (int n: nums)
            map[n]++;
        for (int n: nums){
            // tmp.push_back(n);
            // map[n]--;
            permute2(n, nums);
            // tmp.pop_back();
            // map[n]++;
        }
        return output;
    }
};
