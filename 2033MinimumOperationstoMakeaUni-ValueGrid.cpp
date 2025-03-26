class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int output = 0;
        for (int i = 0;i< size(grid);i++){
            for (int j = 0;j<size(grid[0]);j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int min = arr[0];
        for (int i = 0;i< size(arr);i++){
            arr[i] -= min;
            if(arr[i] % x != 0){
                return -1;
            }else{
                arr[i] = arr[i]/x;
            }
        }
        int middle;
        if(size(arr)%2==0){
            middle = (arr[size(arr)/2] + arr[(size(arr)/2)-1])/2;
        }
        else{
            middle = arr[size(arr)/2];
        }
        // cout<<"middle "<<middle<<endl;
        for (int i = 0;i< size(arr);i++){
            // cout<<"abs "<<abs(arr[i] - middle)<<endl;
            output = output + abs(arr[i] - middle);
        }
        // cout<<min<<endl;
        return output;
    }
};
