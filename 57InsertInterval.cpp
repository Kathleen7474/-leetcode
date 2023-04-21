class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <vector<int>> return_vec;
        for (int i= 0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            // new在右邊
            if(intervals[i][1]<newInterval[0]){
                cout<<"case1"<<endl;
                return_vec.push_back(intervals[i]);
            }
            // new在左邊
            else if(intervals[i][0]>newInterval[1]){
                cout<<"case2"<<endl;
                return_vec.push_back(newInterval);
                newInterval= intervals[i];
                
            }
            else {
                cout<<"case3"<<endl; 
                int start = min(intervals[i][0],newInterval[0]);
                int end = max(intervals[i][1],newInterval[1]);
                newInterval = {start,end};
            }
           
        }
        return_vec.push_back(newInterval);
        return return_vec;
    }
};
// thank you http://www.zrzahid.com/maximum-number-of-overlapping-intervals/
