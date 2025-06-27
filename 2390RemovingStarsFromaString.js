/**
 * @param {string} s
 * @return {string}
 */
var removeStars = function(s) {
    let stk = [];
    for(let i = 0; i<s.length;i++){
        if(s[i]!='*'){
            stk.push(s[i]);
        }else{
            stk.pop();
        }
    }
    return stk.join('');
};
