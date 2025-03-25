class Solution {
public:
    int climbStairs(int n) {
        if (n==0){
            return 0;
        }
        else if (n==1){
            return 1;
        }
        else if (n==2){
            return 2;
        }

        vector<int> cnt(n+1);
        cnt[0] = 0;
        cnt[1] = 1;
        cnt[2] = 2;
        int output = 0;
        for (int i=3; i<n+1 ;i++){
            // cout<<i<<endl;
            output = cnt[i-2]+cnt[i-1];
            cnt[i] = output;
        }
        return output;
    }
};
