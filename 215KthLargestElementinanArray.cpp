class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums){
            if (!pq.empty()){
                // cout<<num<<" num"<<endl;
                if(num>pq.top()||pq.size()<k){
                    pq.push(num);
                }
            }else{
                pq.push(num);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
