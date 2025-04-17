class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for (int num = 0;num<=n;num++){
            int bits = 0;
            if(num==0)
                output.push_back(0);
            else if(num==1)
                output.push_back(1);
            else{
                if(num%2==1)
                    bits = output[num/2]+1;
                else
                    bits = output[num/2];
                output.push_back(bits);
            }
        }
        return output;
    }
};
