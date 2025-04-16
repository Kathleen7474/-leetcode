class Solution {
    // 輸入再x10
    int mul10andRound(long input, bool neg){
        input = input*10;
        if(neg){
            if(input<INT_MIN){
                // cout<<"min"<<endl;
                input = INT_MIN;
            }
        }else{
            if(input>INT_MAX){
                input = INT_MAX;
            }
        }
        return int(input);
    }
public:
    int myAtoi(string s) {
        // 已經有讀數字了，再次遇到non digit
        bool end_flag = false;
        bool neg_flag = false;
        int output = 0;
        // " "也算是一個
        for(int i = 0;i<s.size();i++){
            // cout<<s[i]<<" "<<int(s[i])<<endl;
            if(int(s[i])==32&&!end_flag)
                continue;
            if(int(s[i])==45&&!end_flag){
                end_flag = true;
                neg_flag = true;
                continue;
            }
            if(int(s[i])==43&&!end_flag){
                end_flag = true;
                continue;
            }

            if(int(s[i])<48||int(s[i])>57){
                break;
            }
            // 讀到數字
            if((int(s[i])>=48&&int(s[i])<=57)){
                // output = output*10;
                output = mul10andRound(long(output), neg_flag);
                end_flag = true;
                if(neg_flag&&output>=INT_MIN+int(s[i])-48){
                    output-= int(s[i])-48;
                }else if(neg_flag)
                    output = INT_MIN;
                if(!neg_flag&&output<=INT_MAX-(int(s[i])-48)){
                    output+= int(s[i])-48;
                }else if(!neg_flag)
                    output = INT_MAX;
            }

            
        }
        // if (neg_flag)
        //     output = -output;
        return output;
    }
};
