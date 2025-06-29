/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var output = 0;
    for(let i = 0;i<prices.length;i++){
        // valley
        if(prices[i+1]>prices[i]){
            output = output-prices[i];
            i++;
            while(prices[i+1]>prices[i]&&i<prices.length){
                i++;
            }
            // 跳出來就是找到peak了
            output = output + prices[i];
        }
    }
    return output;
};
