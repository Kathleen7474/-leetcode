/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let output = "";
    let cnt1 = 0, cnt2 = 0;
    while(cnt1<word1.length||cnt2<word2.length){
        if(cnt1<word1.length){
            output += word1[cnt1];
            cnt1++;
        }
        if(cnt2<word2.length){
            output += word2[cnt2];
            cnt2++;
        }
    }
    return output;
};
