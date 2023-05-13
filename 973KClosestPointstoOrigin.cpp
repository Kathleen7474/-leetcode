class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return ((pow(a[0],2)+ pow(a[1],2)) < (pow(b[0],2)+ pow(b[1],2)));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(),cmp);
        return vector<vector <int>> (points.begin(),points.begin() + k);
    }
};
