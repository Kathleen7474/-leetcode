void moveZeroes(int* nums, int numsSize) {
    int cur = 0;
    for (int i = 0;i<numsSize;i++){
        if (nums[i]!=0){
            nums[cur] = nums[i];
            if (cur!=i)
                nums[i] = 0;
            cur++;
        }
    }
}
