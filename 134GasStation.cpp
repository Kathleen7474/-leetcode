class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, tank = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            // 如果總數錯，後面不用談
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];

            // 如果油箱在這一站變負數，表示無法從 start 到這裡
            if (tank < 0) {
                start = i + 1;  // 下一站才有可能是正確起點
                tank = 0;       // 重置油箱
            }
        }
        
        return (total_gas >= total_cost) ? start : -1;
    }
    // 我覺得超奇怪的，但是可以想說total_gas>=total_cost一定有解
    // 那如果i走到j爆了，i+1走到j一定會爆，因為能走i就代表i一定大於0
    // 那爲什麼i不用再繞回去0~i-1 check，是因為已知0~i-1一定是負的
    // 如果後面累積夠的話一定可以突破（因為已知有解）
    // 而且又只有唯一解
    // 超混亂的==

    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int length = gas.size();
    //     vector<int> carry;
    //     for(int i = 0;i<length;i++){
    //         carry.push_back(gas[i] - cost[i]);
    //     }
    //     int last_stop = 0;
    //     for(int i = 0;i<length;i++){
    //         // cout<<"i start"<<i<<endl;
    //         if(carry[i]>=0){
    //             int cur_carry = carry[i];
    //             if(length==1&&cur_carry>=0)
    //                 return 0;
    //             for(int j = 1;j<length;j++){
    //                 if(j+i>=length){
    //                     cur_carry += carry[j+i-length];
    //                 }
    //                 else
    //                     cur_carry += carry[j+i];
    //                 if(cur_carry<0){
    //                     last_stop = i+j;
    //                     i = last_stop;
    //                     break;
    //                 }
    //                 if(j==length-1)
    //                     return i;
    //             }
    //         }
    //     }
    //     return -1;
    // }
};
