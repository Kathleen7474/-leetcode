int search(int* nums, int numsSize, int target) {
    int center = numsSize/2;
    if (numsSize<1)
        return -1;
    // printf("center idx %d, numsSize %d", center, numsSize);
    // printf("idx %d, cur num %d, numssize %d\n",center, nums[center], numsSize);

    if (numsSize==1&&nums[center]!=target){
        // printf("cur num %d, numssize %d return\n", nums[center], numsSize);
        return -1;
    }
    
    if (nums[center]==target){
        // printf("cur num %d, numssize %d found, center %d\n", nums[center], numsSize, center);
        return center;
    }
    else if(nums[center]>target){
        int left = search(nums, center, target);
        if (left!=-1)
            return left;
        else 
            return -1;
    }
    else if(nums[center]<target){
        int right = search(nums+center+1, numsSize-center-1, target);
        if (right!=-1){
            right = right+center+1;
            return right;
        }
        else 
            return -1;

    }
    // int right = search(nums+center+1, numsSize-center-1, target);
    // if (right!=-1){
    //     right = right+center+1;
    //     return right;
    // }
    // else 
    //     return -1;
    return -1;
}
