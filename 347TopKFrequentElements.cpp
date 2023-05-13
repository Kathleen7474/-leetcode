class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int ,int> freq;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]] = freq[nums[i]]+1;
        }
        // for (int i = 0;)
        vector<vector<int>> freq_vec;
        for (const auto& s : freq) {
            freq_vec.push_back(vector<int> {s.first,s.second});
            cout<<freq_vec[0][0]<<" "<<freq_vec[0][1]<<endl;
            // cout << "id: " << s.first << ", name: " << s.second << endl;
        }
        nth_element(freq_vec.begin(), freq_vec.begin() + k, freq_vec.end(),[](vector<int>& p, vector<int>& q) {
            return p[1]>q[1];
        });
        vector<int> return_vec;
        for(int i = 0;i<k;i++){
            return_vec.push_back(freq_vec[i][0]);
        }
        return return_vec;
    }
};
