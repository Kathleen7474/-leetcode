class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // cout<<n<<endl;
        uint32_t output = 0;
        for (int i = 0;i<32;i++){
            output = output+(n%2);
            // output = output+(n>>(32-i));
            // cout<<"i"<<i<<endl;
            // cout<<bitset<32>(n)<<endl;
            // cout<<output<<endl;
            // cout<<bitset<32>(output)<<endl;
            if (i==31)
                break;
            n = n>>1;
            output = output<<1;
        }
        
        return output;
    }
};
