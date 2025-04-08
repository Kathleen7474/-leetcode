class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> step(m, vector<int>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j]==1)
                    step[i][j] = 0;
                else if(i==0&&j==0)
                    step[i][j] = 1;
                else if (i==0)
                    step[i][j] = step[i][j-1];
                else if (j==0)
                    step[i][j] = step[i-1][j];
                else
                    step[i][j] = step[i-1][j] + step[i][j-1];
            }
        }
        return step[m-1][n-1];
    }
};
