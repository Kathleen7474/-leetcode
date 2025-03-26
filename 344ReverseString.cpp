class Solution {
public:
    void reverseString(vector<char>& s) {
        auto left_ptr = s.begin();
        auto right_ptr = s.end()-1;
        cout<<*left_ptr<<endl;
        cout<<*right_ptr<<endl;
        for (int i = 0; i<size(s)/2;i++){
            char tmp = *left_ptr;
            *left_ptr = *right_ptr;
            *right_ptr = tmp;
            // cout<<*left_ptr<<endl;
            // break;
            left_ptr++;
            right_ptr--;
        }
    }
};
