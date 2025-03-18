void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int cur = 0;
    int back = numsSize-1;
    int *arr = (int *)malloc(numsSize*sizeof(int));
    for (i = 0;i<numsSize;i++){
        if (nums[i]==0){
            arr[i] = back;
            back--;
        }else{
            arr[i] = cur;
            cur++;
        }
    }
    int tmp = nums[0];
    int next;
    int tmp_idx = 0;
    int next_idx = 0;
    for(i=0;i<numsSize;i++){
         if(arr[tmp_idx]==-1){
            for (int j = 0;j<numsSize;j++){
                if (arr[j]!=-1){
                    tmp_idx = arr[j];
                    tmp = nums[tmp_idx];
                }
            }
        }
        if (arr[tmp_idx] == tmp_idx){
            // 原本住在這裡的人
            // printf("?\n");
            if (i==numsSize-1)
                break;
            tmp_idx++;
            tmp = nums[tmp_idx];
        }
        else{
            // 目標人是誰
            next = tmp;
            next_idx = tmp_idx;
            tmp = nums[arr[tmp_idx]];
            // 我住到目標人家
            nums[arr[tmp_idx]] = next;
            // 目標人id
            tmp_idx = arr[tmp_idx];
            arr[next_idx] = -1;
        }
    }
}
