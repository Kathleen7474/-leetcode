class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        if (n<0){
            x = 1/x;
            nn = -nn;
        }else if(n==0)
            return 1;
        // double output = x;

        double output = 1;
        double base = x;
        // int HBP = 0;
        long num = nn;
        // vector<int> idx;
        while (num > 0) {
            // cout<<" "<<num%2;
            if(num%2==1){
                // idx.push_back(HBP);
                output = output*base;
                // cout<<" HBP 1"<<HBP<<" ";
            }
            base = base*base;
            num >>= 1;  // 右移一位
            // HBP++;  // 記錄已移動的次數
        }
        return output;
        // cout<<endl;        
        // vector<double> store_n(HBP);
        // double tmp = output;
        // store_n[0] = tmp;
        // for (int i = 1;i<HBP;i++){
        //     tmp = tmp*tmp;
        //     store_n[i] = tmp;
        //     // cout<<tmp<<" ";
        // }
        // output = 1;
        // for(int i=0;i<idx.size();i++){
        //     output = store_n[idx[i]]*output;
        // }

        // return output;
    }
};
