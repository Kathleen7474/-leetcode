class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output(size(digits), 0);
        int d_size = size(digits);
        int carry = 1;
        for (int i = 0;i<d_size;i++){
            // cout<<digits[d_size-i-1]<<endl;
            output[d_size-i-1] = (digits[d_size-i-1]+carry) %10;
            if((digits[d_size-i-1]+carry)>=10){
                carry = 1;
            }
            else 
                carry = 0;
        }
        // cout<<"c "<<carry<<endl;
        if (carry == 1)
            output.insert(output.begin(), 1);
        return output;
    }
};
