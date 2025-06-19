class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix[0].size(),n = matrix.size();
        bool first_row_0 = false, first_col_0 = false;
        // 初始設定
        for(int i = 0;i<m;i++){
            if(matrix[0][i]==0) 
                first_row_0 = true;
        }
        for(int i = 0;i<n;i++){
            if(matrix[i][0]==0) 
                first_col_0 = true;
        }
        // 找出要變成0的row and column
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 變成0
        for(int i = 1;i<m;i++){
            if(matrix[0][i]==0) 
                for(int j = 0;j<n;j++)
                    matrix[j][i] = 0;
        }
        for(int i = 1;i<n;i++){
            if(matrix[i][0]==0) 
                for(int j = 0;j<m;j++)
                    matrix[i][j] = 0;
        }

        if(first_row_0){
            for(int i = 0;i<m;i++)
                matrix[0][i] = 0;
        }
        if(first_col_0){
            for(int i = 0;i<n;i++)
                matrix[i][0] = 0;
        }
    }

};
