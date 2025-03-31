class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int max_days = 0;
        int days;
        int y_size = size(grid[0]), x_size = size(grid);
        vector<vector<int>> checked(x_size, vector<int>(y_size, -1));
        for (int i = 0;i<x_size;i++){
            for (int j = 0;j<y_size;j++){

                if (checked[i][j] == -1 && grid[i][j] == 0){
                    checked[i][j] = 0;
                }else 

                if (checked[i][j] == -1 && grid[i][j] == 2){
                    bfs(grid, checked, i, j);
                }
            }
        }

        for (int i = 0;i<x_size;i++){
            for (int j = 0;j<y_size;j++){
                // cout<<checked[i][j]<<" ";
                if(checked[i][j]==-1){
                    return -1;
                }else if(checked[i][j]>max_days)
                    max_days = checked[i][j];
            }
            // cout<<endl;
        }
        // 最後檢查如果還有任何一顆好橘子max_days = -1
        return max_days;
    }
private:
    void bfs(vector<vector<int>>& grid,  vector<vector<int>>& checked, int base_i,int base_j){
        // 這三個每次都要歸0
        int i = base_i, j = base_j;
        int days = 0;
        checked[i][j] = days;
        queue<vector<int>> bfs_q;
        bfs_q.push({i,j});
        while(!bfs_q.empty()){
            auto front = bfs_q.front(); 
            i = front[0];
            j = front[1];
            // cout<<"pop "<<i<<" "<<j<<endl;
            days = checked[i][j];
            bfs_q.pop();
            // 找鄰居橘子
            if(i>0){
                if(grid[i-1][j]==1){
                    // cout<<"左"<<endl;
                    if(checked[i-1][j]!=-1&&checked[i-1][j]<days+1){
                        
                    }else{   
                        bfs_q.push({i-1,j});
                        checked[i-1][j] = days+1;
                    }
                }
            }
            if(i<size(grid)-1){
                if(grid[i+1][j]==1){
                    // cout<<"右"<<endl;
                    if(checked[i+1][j]!=-1&&checked[i+1][j]<days+1){
                       
                    }
                    else{
                        checked[i+1][j] = days+1;
                        bfs_q.push({i+1,j});
                    } 
                }
            }
            if(j>0){
                if(grid[i][j-1]==1){
                    // cout<<"上"<<endl;

                    if(checked[i][j-1]!=-1&&checked[i][j-1]<days+1){
                    }
                    else{
                        bfs_q.push({i,j-1});
                        checked[i][j-1] = days+1;
                    }
                }
            }
            if(j<size(grid[0])-1){
                if(grid[i][j+1]==1){
                    // cout<<"下"<<endl;
                    if(checked[i][j+1]!=-1&&checked[i][j+1]<days+1){
                    }else{
                        bfs_q.push({i,j+1});
                        checked[i][j+1] = days+1;
                    }
                    
                }  
            }
        }
    }
};
