class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> steps(m, vector<int>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0||j==0){
                    steps[i][j] = 1;
                }
                else{
                    steps[i][j] = steps[i-1][j]+steps[i][j-1];
                }
            }
        }
        return steps[m-1][n-1];
    }
};
