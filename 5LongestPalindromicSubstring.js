/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var output = "";
    for(let i = 0; i <2 * s.length - 1; i++){
        let left = Math.floor(i/2);
        let right = left + i % 2;
        while(left>=0 &&right<s.length &&s[left]==s[right]){
            // var str = s.substr(left, right-left+1);
            // console.log(str, "left", left, 'right', right);
            // output.push(str);
            if(right-left+1>output.length){
                output = s.substr(left, right-left+1);
            }
                
            left--;
            right++;
        }
    }
    return output;
};
