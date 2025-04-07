class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int MAX_SUM = 4999;
        bitset<MAX_SUM + 1> dp;
        dp.reset();
        for (int j = 0;j<mat[0].size();j++){
            dp[mat[0][j]] = 1;
        }
        for(int i = 1;i<mat.size();i++){
            bitset<MAX_SUM + 1> new_dp;
            for (int j = 0;j<mat[0].size();j++){
                new_dp |= dp<<mat[i][j];
            }
            dp = new_dp;
        }
        // 會超過餒...
        // 存上一輪加入的
        // deque<int> dq;
        // int dq_size = 0;
        // int remain;
        // for(int i = 0;i<mat.size();i++){
        //     for (int j = 0;j<mat[0].size();j++){
        //         if(i == 0){
        //             remain = target-mat[i][j];
        //             auto it = find(dq.begin(), dq.end(), remain);
        //             if((it-dq.begin())<dq_size){
        //                 dq.push_back(remain);
        //             }
        //             if(it==dq.end())
        //                 dq.push_back(remain);
        //         }else{
        //             for(int k = 0;k<dq_size;k++){
        //                 remain = dq[k]-mat[i][j];
        //                 auto it = find(dq.begin(), dq.end(), remain);
        //                 if((it-dq.begin())<dq_size){
        //                     dq.push_back(remain);
        //                 }
        //                 if(it==dq.end())
        //                     dq.push_back(dq[k]-mat[i][j]);
        //             }
        //         }
        //     }
        //     for(int j = 0;j<dq_size;j++){
        //         dq.pop_front();
        //     }
        //     removeDuplicatesKeepFirst(dq);
        //     dq_size = dq.size();
        // }
        int res = INT_MAX;
        for(int i = 0;i<=MAX_SUM;i++){
            if(dp[i]==1)
                res = min(res, abs(target - i));
        }
        return res;
    }
};
