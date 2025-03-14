class Solution {
public:
// 暴力解不管用= =
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_diff = INT_MAX;
        auto [mn, mx] = minmax_element(begin(arr), end(arr));
        int R = *mx - *mn + 1;
        int shift = -*mn, minDiff = INT_MAX, curDiff, prevElement = -R;
        vector<vector<int>> output;
        vector<bool> seen(R);

        // 遍歷A裡面的元素 c就是A[0], A[1]...依序
        // 假設arr = [1,3,6,10,15]，那seen[idx]為true的idx有0,2,5,9,14，其餘為false
        for (int c: arr){
            seen[c+shift] = true;
            // cout<<c+shift<<endl;
        }

        for (int i =0;i<R;i++){
            if(seen[i]){
                // 轉回正常數字
                int a = prevElement - shift, b = i - shift;
                curDiff = b-a;
                if (curDiff==minDiff){
                    vector<int> pair = {a,b};
                    output.push_back(pair);
                }
                else if( curDiff<minDiff){
                    minDiff = curDiff;
                    output = {{a,b}};
                }
                prevElement = i;
            }
        }
        
        return output;
    }
};
