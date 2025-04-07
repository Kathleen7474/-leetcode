class Solution {
    // vector<pair<int, int>> m;
    vector<vector<int>> output;
    vector<int> tmp;
    int in_n;
    void comb(int n, int step){
        if (step==1){
            tmp.push_back(n);
            output.push_back(tmp);
        }else{
            // 找下一個人
            tmp.push_back(n);
            for (int i = n+1;i<in_n+1;i++) {
                comb(i, step-1);
            }
        }
        tmp.pop_back();
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        in_n = n;
        for(int i = 1;i<n+1;i++){
            comb(i,k);
        }
        return output;
    }
};77. Combinations
