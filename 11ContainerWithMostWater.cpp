class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area;
        vector<int>sorted_idx(height.size());
        for (int i = 0; i < height.size(); i++) sorted_idx[i] = i;
        sort(sorted_idx.begin(), sorted_idx.end(), [&](int i, int j) {
            return height[i] > height[j];  // 降序排序
        });
        max_area = height[sorted_idx[1]]*(abs(sorted_idx[1]-sorted_idx[0]));
        for(int i = 2;i<height.size();i++){
            if((height.size()*height[sorted_idx[i]])<max_area)
                return max_area;
            int tmp_area = 0;
            for(int j = 0;j<i;j++){
                tmp_area = height[sorted_idx[i]]*(abs(sorted_idx[i]-sorted_idx[j]));
                if(tmp_area>max_area)
                    max_area = tmp_area;
            }
        }
        return max_area;
    }
};
