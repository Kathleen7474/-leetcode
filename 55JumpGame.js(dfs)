/**
 * @param {number[]} nums
 * @return {boolean}
 */


var canJumpFromPos = function(cur_idx, nums){
    let jump_try = nums[cur_idx];
    if(jump_try==0&&cur_idx == nums.length-1)
        return true;
    // console.log("jump_try",jump_try, "cur_idx", cur_idx);
    for(let i = 1;i<=jump_try;i++){
        cur_idx = cur_idx+i;
        // console.log(cur_idx);
        if(cur_idx>=nums.length-1){
            return true;
        }
        var result = canJumpFromPos(cur_idx,nums);
        if(result){
            return true;
        }
        cur_idx -=i;
    }   
    return false; 
}
var canJump = function(nums) {
    const memo = new Array(nums.length).fill(0);
    function dfs(cur_idx){
        let jump_try = nums[cur_idx];
        if(jump_try==0&&cur_idx == nums.length-1)
            return true;
        for(let i = 1;i<=jump_try;i++){
            cur_idx = cur_idx+i;
            if(cur_idx>=nums.length-1){
                return true;
            }
            var result;
            if(memo[cur_idx]==0){
                result = dfs(cur_idx);
                if(result){
                    memo[cur_idx] = 1;
                    return true;
                }else{
                    memo[cur_idx] = -1
                }
            }else if(memo[cur_idx]==1){
                return true;
            }
            
            cur_idx -=i;
        }   
        return false;
    }
    return dfs(0);
};
