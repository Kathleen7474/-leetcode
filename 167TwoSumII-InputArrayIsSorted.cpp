class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = size(numbers)-1;

        vector<int> output;
        while(left<right){
            int sum  = numbers[left] + numbers[right];
            if (sum == target){
                output.push_back(left+1);
                output.push_back(right+1);
                return output;
            }
            else if(sum>target){
                right--;
            }
            else if (sum<target){
                left++;
            }
        }
        return output;
    }
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     vector<int> output;
       
    //     int n_size = size(numbers);
    //     vector<int> remain_n(n_size, INT_MIN);
    //     cout<<"n size "<<n_size<<endl;
    //     int ptr = 0;
    //     for (int i = 0; i<n_size; i++){
    //         cout<<"round "<<i<<endl;
    //         int remain = target - numbers[i];
    //         if (remain_n[i] == INT_MIN){
    //             // cout<<"hello";
    //             remain_n[i]= remain;
    //         }
    //         int flag = 0;
    //         for (int j = i+1;j<n_size;j++){
    //             if (numbers[i]==numbers[j]){
    //                 ptr = j;
    //                 flag = 1;
    //                 // i = ptr;
    //             }
    //             // cout<<"i "<<numbers[i]<<" remain "<<remain_n[i]<<" now j "<<numbers[j]<<endl;
    //             if (remain_n[i]==numbers[j]){
    //                 output.push_back(i+1);
    //                 output.push_back(j+1);
    //                 return output;
    //             }else if(remain_n[j] == INT_MIN)
    //             {
    //                 remain = target - numbers[j];
    //                 remain_n[j]=remain;
    //             }
    //         }
    //         if (flag ==1){
    //             i = ptr;
    //         }
    //     }
    //     return output;
    // }
};
