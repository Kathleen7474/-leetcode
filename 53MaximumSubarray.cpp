class Solution {
public:


    int maxSubArray(vector<int>& nums) {
//         註解是可以動的
        // int max[nums.size()];
        // int global_max = nums[0];
        // max[0] = nums[0];
        // for (int i = 1;i<nums.size();i++){
        //     if(max[i-1]+nums[i]>nums[i]){
        //         max[i] = max[i-1]+nums[i];
        //     }
        //     else
        //         max[i] = nums[i];
        //     if (global_max<max[i])
        //         global_max = max[i];
        // }
        if(nums.size()==1)
            return nums[0];
        vector<int> v2(nums.begin(), nums.begin()+(nums.size()/2));
        vector<int> v3(nums.begin()+(nums.size()/2)+1, nums.end());
        int global_max = 0;
        int left_max;
        int right_max;
        int center_max;
        int center_right_max = nums[(nums.size()/2)+1];
        int center_left_max = nums[(nums.size()/2)];
        int center_right = nums[(nums.size()/2)+1];
        int center_left = nums[(nums.size()/2)];
        cout<<nums[0]<<" "<<nums.size()<<endl;
        cout<<"center_right"<<center_right<<endl;
        for (int i = 1;i<nums.size()/2;i++){
            center_right +=nums[(nums.size()/2)+1+i];
            if (center_right > center_right_max)
                center_right_max = center_right;
            center_left +=nums[(nums.size()/2)+1+i];
            if (center_left > center_left_max)
                center_left_max = center_left;
        }
        
        if(nums.size()%2==0){
            center_right += nums[nums.size()-1];
            if (center_right > center_right_max)
                center_right_max = center_right;
        }
        center_max = center_left_max + center_right_max;
        left_max = maxSubArray (v2);
        right_max = maxSubArray (v3);
        if (left_max>right_max)
            global_max = left_max;
        else 
            global_max = right_max;
        if (center_max>global_max)
            global_max = center_max;
        return global_max;
    }
};
