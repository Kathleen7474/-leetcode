/**
 * @param {number[]} nums
 * @return {boolean}
 */

var canJump = function(nums) {
    let max_reach = 0;
    for(let i = 0;i<nums.length;i++){
        if(i>max_reach){
            return false;
        }
        max_reach = Math.max(i+nums[i], max_reach);
    }
    return true;
};
