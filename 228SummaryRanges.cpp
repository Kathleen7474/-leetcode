class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int tmp_start, cur_id;
        int prev;
        string tmp_str;
        vector<string> output;
        int i = 1;

        for(int i = 0;i<nums.size();i++){
            tmp_start = nums[i];
            if(i!=nums.size()-1&&nums[i+1]==nums[i]+1){
                prev = nums[i];
                for(int j = i+1;j<nums.size();j++){
                    if(nums[j]!=prev+1){
                        break;
                    }
                    cur_id = j;
                    cout<<"nums[i]"<<nums[i]<<" cur "<<nums[j]<<endl;
                    prev = nums[j];
                }
                // 如果是因為是最後一項而跳出回圈會跟現在的寫法不一樣
                // cur_id--;
                tmp_str = to_string(nums[i]) + "->" + to_string(nums[cur_id]);
                i = cur_id;
            }
            else{
                cout<<"else nums[i]"<<nums[i]<<endl;
                tmp_str = to_string(nums[i]);
            }
            output.push_back(tmp_str);
        }

        return output;
    }
};
