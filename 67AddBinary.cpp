class Solution {
public:
    string addBinary(string a, string b) {
        string output;
        int l = (a.size() > b.size()) ? 1 : 0;
        int shorter, longer;
        string longer_str;
        if (l == 1){
            shorter = b.size();
            longer = a.size();
            longer_str = a;
        }
        else{
            shorter = a.size();
            longer = b.size();
            longer_str = b;
        }
        int tmp = 0;
        for(int i = 0;i<shorter;i++){
            int int_a = int(a[a.size()-i-1]-48);
            int int_b = int(b[b.size()-i-1]-48);
            // cout<<"inta "<<int_a<<"int_b"<<int_b<<"add "<<int_a+int_b+tmp<<endl;
            if((int_a+int_b+tmp)>=2){
                if(int_a+int_b+tmp==2) {
                    output.push_back('0');
                }
                else
                    output.push_back('1');
                tmp = 1;
            }
            else
            {   
                output.push_back(int_a+int_b+tmp+'0');
                tmp = 0;
                // cout<<"tmp " <<tmp<<endl;
            } 
            // cout<<"i "<<i<<" push "<<output<<endl;
        }
        
        for(int i = shorter;i<longer;i++){
            // cout<<"cnt "<<i<<endl;
            int int_l = int(longer_str[longer_str.size()-1-i]-48);
            // cout<<"intl "<<int_l<<endl;
            if(int_l+tmp==2){
                tmp = 1;
                output.push_back('0');
            }else{
                // cout<<"咦"<<static_cast<char>(int_l|tmp)<<endl;
                output.push_back((int_l|tmp)+'0');
                tmp = 0;
            }
            // cout<<"i "<<i<<" push "<<output<<endl;
            // cout<<"tmp "<<tmp<<endl;
        }
        if(tmp==1){
            output.push_back('1');
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
