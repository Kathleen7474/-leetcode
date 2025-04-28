class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 最小不一定是0
        int left = 0, right = nums.size()-1;
        int mid = (left+right)/2;
        while(nums[mid]!=target){
            if(nums[left]==target){
                return left;
            }else if(nums[right]==target){
                return right;
            }
            // 左邊是正常的
            if(nums[left]<nums[mid]){
                // 比較小
                if(target<nums[mid]){
                    // 有兩種可能1. 整排都正常了 2. 後面有反轉
                    // 後排有反轉
                    if(nums[right]<nums[left]){
                        // 在正常的區段
                        if(target>nums[right])
                            right = mid;
                        // 在後面
                        else
                            left = mid;
                    }
                    // 整排正常
                    else if(nums[right]>nums[left]){
                        right = mid;
                    }
                }
                // 比較大
                else{
                    left = mid;
                }
            }
            // 右邊是正常的
            else{
                // 比較大
                if(target>nums[mid]){
                    // 在正常的區段
                    // 1.有反轉
                    if(nums[right]<nums[left]){
                        // 在後面區段
                        if(target<nums[left]){
                            left = mid;
                        }else{
                            right = mid;
                        }
                    // 整段正常
                    }else if(nums[right]>nums[left]){
                        left = mid;
                    }
                    
                }else
                    right = mid;
                
            }
            mid = (left+right)/2;
            if(left == right&&nums[left]!=target){
                return -1;
            }
            if((left == right-1)&&nums[left]!=target&&nums[right]!=target)
                return -1;
        }
        return mid;        
    }
};
