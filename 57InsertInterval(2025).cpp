class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        int i = 0, n = intervals.size();
        if(intervals.size()==0){
            output.push_back(newInterval);
            return output;
        }
        // newinterval之前的
        while(i<n&&intervals[i][1]<newInterval[0]){
            output.push_back(intervals[i]);
            i++;
        }
        // 下一個有可能interval尾巴大於newinterval
        // 看誰的頭比較小用誰？

        // 所有頭小於newinterval尾巴
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0] = (min(intervals[i][0], newInterval[0]));
            newInterval[1] = (max(intervals[i][1], newInterval[1]));
            i++;
        }
        output.push_back(newInterval);
        

        while(i<n){
            output.push_back(intervals[i]);
            i++;
        }
        return output;
        
        // intervals.push_back(newInterval);
        // sort(intervals.begin(),intervals.end());
        // for(const auto & interval: intervals){
        //     if(output.empty()||output.back()[1]<interval[0]){
        //         output.push_back(interval);
        //     }else{
        //         output.back()[1] = max(interval[1], output.back()[1]);
        //     }
        // }
        return output;
    }
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     vector<vector<int>> output;
    //     if(intervals.size()==0){
    //         output.push_back(newInterval);
    //         return output;
    //     }
    //     int last = max(intervals[intervals.size()-1][1], newInterval[1]);
    //     vector<int> color(last+1, 0);
    //     // cout<<"last "<<last<<endl;
    //     // cout<<"intervals size"<<intervals.size()<<endl;
        
    //     for(const auto &interval: intervals){
    //         for(int i = interval[0];i<interval[1];i++){
    //             color[i] = 1;
    //         }
    //         if(color[interval[1]]==0)
    //             color[interval[1]] = 2;
    //     }
    //     for(int i = newInterval[0];i<newInterval[1];i++){
    //         color[i] = 1;
    //     }
    //     if(color[newInterval[1]]==0)
    //         color[newInterval[1]] = 2;
        

    //     // for(int i =0;i<=last;i++){
    //     //     cout<<color[i]<<" ";
    //     // }
    //     int i = 0;
    //     while(i<=last){
    //         vector<int> tmp;
    //         while(color[i]==1){
    //             if (tmp.empty())
    //                 tmp.push_back(i);
    //             i++;
    //         }
    //         // 如果是自己一個人的interval
    //         if(color[i]==2&&(i==0)){
    //             tmp.push_back(i);
    //             tmp.push_back(i);
    //             output.push_back(tmp);
    //         }else if(color[i]==2&&(color[i-1]!=1)){
    //             tmp.push_back(i);
    //             tmp.push_back(i);
    //             output.push_back(tmp);
    //         }
    //         else if (color[i]==2){
    //             tmp.push_back(i);
    //             output.push_back(tmp);
    //         }
    //         i++;
    //     }
    //     return output;
    // }
};
