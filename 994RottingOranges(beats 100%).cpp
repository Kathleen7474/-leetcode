class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max_days = 0;
        int y_size = size(grid[0]), x_size = size(grid);
        queue<pair<int, int>> bfs_q;
        int fresh_oranges = 0;
        for (int i = 0;i<x_size;i++){
            for (int j = 0;j<y_size;j++){
                if(grid[i][j] == 2){
                    bfs_q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    fresh_oranges++;
            }
        }
        if (fresh_oranges==0){
            return 0;
        }
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!bfs_q.empty()){
            // 同一個dist有多少人
            int q_size = bfs_q.size();
            bool has_rotten = false; //?
            // loop裡面的點
            for(int i = 0;i<q_size;i++){
                auto [x,y] = bfs_q.front();
                bfs_q.pop();
                // 上下左右
                for(auto direct: directions){
                    int nx = x + direct[0];
                    int ny = y + direct[1];
                    // 找鄰居橘子
                    if(nx >= 0 && nx < x_size && ny >= 0 && ny < y_size && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;  // 標記為腐爛
                        bfs_q.push({nx, ny});
                        has_rotten = true;
                        fresh_oranges--;
                    }
                }
            }
            if (has_rotten) max_days++;
        }
        if (fresh_oranges>0){
            return -1;
        }
        return max_days;
    }
};
