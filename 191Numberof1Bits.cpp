class Solution {
public:
    int hammingWeight(int n) {
        int bits = n%2;
        n = n/2;
        while(n>0){
            if(n%2==1)
                bits++;
            n = n/2;
        }
        return bits;
    }
};
