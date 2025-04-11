class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans; 

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (mp.find(temp) != mp.end()) {
                ans[mp[temp]].push_back(strs[i]);
            } else {
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         // 存idx
//         unordered_map<int, vector<int>> map_idx;
//         int count = 0;
//         vector<string> group;
//         for(int i = 0;i<strs.size();i++){
//             string tmp = strs[i];
//             sort(tmp.begin(), tmp.end());
//             bool flag = false;
//             for(int j = 0;j<count;j++){
//                 if(tmp == group[j]){
//                     map_idx[j].push_back(i);
//                     flag = true;
//                     break;
//                 }
//             }
//             if(!flag){
//                 count++;
//                 group.push_back(tmp);
//                 map_idx[count-1].push_back(i);
//                 // cout<<"group "<<tmp<<" idx "<<count<<endl;
//             }
//         }
//         vector<vector<string>> output;
//         for (const auto&  [key, idxs] : map_idx) {
//             vector<string> tmp;
//             for(int idx: idxs){
//                 // cout<<idx<<" ";
//             }
//             // cout<<"key "<<key<<endl;
//             for(int idx: idxs){
//                 tmp.push_back(strs[idx]);
//             }
//             output.push_back(tmp);
//         }
//         return output;

//     }
// };
