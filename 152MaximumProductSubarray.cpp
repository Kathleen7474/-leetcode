class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int output = nums[0];
        for (int i = 1; i<nums.size();i++){
            if(nums[i]<0){
                swap(max_prod, min_prod);
            }
            max_prod = max(max_prod*nums[i], nums[i]);
            min_prod = min(min_prod*nums[i], nums[i]);
            // cout<<"nums "<<nums[i]<<" max "<<max_prod<<" min "<<min_prod<<endl;
            output = max(output, max_prod);
        }
        return output;
    }
};
