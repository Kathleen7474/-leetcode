class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int y_size = size(grid[0]), x_size = size(grid);
        vector<vector<int>> checked(x_size, vector<int>(y_size, 0));
        // cout<<"checked x"<< size(checked[0])<<" y "<<size(checked)<<endl;
        int iland_cnt = 0;
        for (int i = 0;i<x_size;i++){
            for (int j = 0;j<y_size;j++){
                // cout<<"i "<<i<<" j "<<j<<" grid "<<grid[i][j]<<" checked "<<checked[i][j]<<endl;
                if (checked[i][j] == 0 && grid[i][j] == '0'){
                    // cout<<"?"<<endl;
                    checked[i][j] = 1;
                }else if (checked[i][j] == 0 && grid[i][j] == '1'){
                    // cout<<"check i "<<i<<" j "<<j<<endl;
                    traversal(grid, checked, i, j);
                    // cout<<"i "<<i<<" j "<<j<<" grid "<<grid[i][j]<<" checked "<<checked[i][j]<<endl;

                    iland_cnt++;
                }
            }
        }
        return iland_cnt;
    }
private:
    void traversal(vector<vector<char>>& grid,  vector<vector<int>>& checked, int i,int j){
        // 上下左右各1
        checked[i][j] = 1;
        // cout<<"i "<<i<<" j "<<j<<" grid "<<grid[i][j]<<" checked "<<checked[i][j]<<endl;
        if(i>0){
            if(checked[i-1][j] == 0&&grid[i-1][j]=='1')   traversal(grid, checked, i-1, j); 
        }
        if(i<size(grid)-1){
            if(checked[i+1][j] == 0&& grid[i+1][j]=='1')   traversal(grid, checked, i+1, j); 
        }
        if(j>0){
            if(checked[i][j-1] == 0&&grid[i][j-1]=='1')   traversal(grid, checked, i, j-1); 
        }
        // cout<<"right margin = "<<size(grid)<<endl;
        // cout<<"depth margin = "<<size(grid[0])<<endl;

        if(j<size(grid[0])-1){
            // cout<<"right most: i "<<i<<" j "<<j<<endl;
            if(checked[i][j+1] == 0&&grid[i][j+1]=='1')   traversal(grid, checked, i, j+1); 
        }
        return;
    }
};
