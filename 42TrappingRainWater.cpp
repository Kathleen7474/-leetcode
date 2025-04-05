class Solution {
public:
    int trap(vector<int>& height) {
        
        int pool = 0;
        // height, idx
        stack<pair<int, int>> prev;
        int start = 0;
        while(start<height.size()&&height[start]==0){
            start++;
        }
        if (start==height.size())
            return pool;
        // 第一個高點

        // 好像不用push進去，要啦
        prev.push({height[start], start});

        start++;
        // pair<int, int> top = {height[start], start};
        while(start<height.size()){

            // push
            if(height[start]<prev.top().first){
                prev.push({height[start], start});
            }
            // pop
            if(height[start]>prev.top().first){
                // 如果要pop的時候
                // 另一個條件是，我要比roof高，否則結束
                while(!prev.empty()&&height[start]>prev.top().first){
                    pair<int, int> floor = prev.top();
                    prev.pop();
                    // 根本都是地板
                    if (prev.empty())
                        break;
                    pair<int, int> roof = prev.top();
                    // 還要看誰比較高
                    int roof_height = min(roof.first, height[start]);
                    pool = pool + (roof_height-floor.first)*(floor.second-roof.second);
                    // 填一個地板回去
                    if (roof_height==roof.first){
                        prev.top().second = floor.second;
                    }
                }
                // 最後記得把最高點push進去
                prev.push({height[start], start});
            }
            // 高度一樣
            if(height[start]==prev.top().first){
                // 且下面根本沒有東西，要更新懸崖位置
                prev.top().second = start;
            }
            start++;

        }
        return pool;
    }
};
