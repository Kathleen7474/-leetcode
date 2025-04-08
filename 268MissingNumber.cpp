class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, max = INT_MIN;
        for(int n: nums){
            sum = sum+n;
            // if(n>max){
            //     max = n;
            // }
        }
        for(int i = 0;i<nums.size()+1;i++){
            sum = sum-i;
        }
        return -sum;
    }
};
