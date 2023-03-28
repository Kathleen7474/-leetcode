class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)    
            return false;
        else {
            double log = log10(n)/log10(3);
            cout<<log<<endl;
            if(log - int(log) ==0 )
                return true;
            else 
                return false;
        }
        return false;
    }
};
