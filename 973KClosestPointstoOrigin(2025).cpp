class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> output;

        // 如果寫auto: point : points會產生一次額外的複製
        // auto: &point : points就不會，但是可能會更動到原本的points
        // 因此才要&還有const
        for (const auto& point : points) {
            int dist = pow(point[0],2) + pow(point[1],2);
            pq.push({dist, point});
            if (pq.size() > k) { 
                pq.pop(); // 維持 heap 的大小為 k
            }
        }
        while (!pq.empty()) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
        // my寫法O(N log N)
        // unordered_map <int, vector<vector<int>>> m;
        // vector<int> sort_dist;
        // for (int i = 0; i<size(points);i++){
        //     int dist = pow(points[i][0],2) + pow(points[i][1],2);
        //     m[dist].push_back(points[i]);
        //     sort_dist.push_back(dist);
        // }
        // int cnt = 0;
        // vector<vector<int>> output;
        // sort(sort_dist.begin(), sort_dist.end());
        // int i = 0;
        // while(size(output)<k){
        //     for (vector<int> pos: m[sort_dist[i]]){
        //         output.push_back(pos);
        //         if (size(output)==k)
        //             return output;
        //     }
        //     i++;
        // }
        // return output;
    }
};
