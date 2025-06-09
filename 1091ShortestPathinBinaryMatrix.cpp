class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = -1;
        if(grid[0][0]==1)
            return ans;
        queue<pair<int, int>> q;
        // 好像會用visited當作紀錄路徑長？
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        visited[0][0] = 1;
        pair<int, int> pos;
        pos = {0,0};
        q.push(pos);
        pair<int, int> end  = {grid.size()-1,grid[0].size()-1};
        if(pos==end)
            return 1;
        // cout<<"end pos"<<end.first<<" "<<end.second<<endl;

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {1,1},{1,-1},{-1,-1},{-1,1},{0,-1},{-1,0}};
        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            // 無路可走也return -1
            for(auto[dx, dy]: directions){
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < end.first+1 && ny >= 0 && ny < end.second+1 &&
                grid[nx][ny] == 0 && visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    pos = {nx, ny};
                    // cout<<"visiting"<<nx<<" "<<ny;
                    // cout<<" path length"<<visited[nx][ny]<<endl;
                    if(pos==end){
                        ans = visited[nx][ny];
                        return ans;
                    }
                    q.push(pos);
                }
            }
        }
        return ans;
    }
};
