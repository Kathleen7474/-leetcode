class Solution {

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        unordered_map<char, int> inq;
        for(auto t:tasks){
            map[t]++;
        }
        // 紀錄誰有幾次
        vector<pair<char, int>> task_cnt;
        for (const auto& [key, n_task] : map) {
            task_cnt.push_back({key, n_task});
        }
        sort(task_cnt.begin(), task_cnt.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        int count = 0;
        deque<char> dq;
        int max_task = task_cnt[0].second;
        while(max_task>0){
            // 有找到的flag
            bool flag = false;
            for(auto& [ch, cnt] : task_cnt){
                int i = 0;
                if(dq.front()==ch&&dq.size()==n+1){
                    dq.pop_front();
                    dq.push_back(ch);
                    cnt--;
                    count++;
                    flag = true;
                }
                if(inq[ch]!=1){
                    if(dq.size()==n+1){
                        inq[dq.front()] = 0;
                        dq.pop_front();
                    }
                    dq.push_back(ch);
                    inq[ch] = 1;
                    cnt--;
                    count++;
                    flag = true;
                }
                if(flag==true){
                    break;
                }
            }
            if(!flag){
                count++;
                // cout<<"in x"<<dq.front()<<endl;
                if(dq.size()==n+1){
                    inq[dq.front()] = 0;
                    dq.pop_front();
                }
                dq.push_back('x');
                // cout<<"x"<<endl;
            }
            sort(task_cnt.begin(), task_cnt.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });
            max_task = task_cnt[0].second;
        }
        
        return count;
    }
};
