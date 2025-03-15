class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.size();
        stack<char> a;
        string output;
        int max_len = 0;
        if (str_len == 1)
            return s;
        for (int i=1;i<=s.size()-1;i++){
            stack<char> a;
            int one_flag = 0;
            string tmp_a, tmp_b;
            cout<<"stack ";
            for (int j = 0; j<i;j++){
                a.push(s[j]);
                // cout<<' '<<s[j];
            }
            cout<<endl;
            stack<char> b = a;
            // 偶數
            int j = 0;
            while(!a.empty()){
                // cout<<"a前 "<<a.top()<<" 後 "<<s[i+j]<<endl;
                if(a.top() == s[i+j]){
                    tmp_a.push_back(a.top());
                    a.pop();
                }else
                    break;
                j++;
            }
            // 奇數
            tmp_b = b.top();
            j = 0;
            b.pop();
            while(!b.empty()){
                // cout<<"b前 "<<b.top()<<" 後 "<<s[i+j]<<endl;
                if(b.top() == s[i+j]){
                    tmp_b.push_back(b.top());
                    b.pop();
                }else
                    break;
                j++;
            }
            
            //看誰比較長
            int tmp_a_len = tmp_a.size()*2;
            int tmp_b_len = tmp_b.size()*2-1;
            int tmp_len = max(tmp_a_len, tmp_b_len);
            if (tmp_len>max_len){
                string tmp_output;
                max_len = tmp_len;
                if (tmp_a_len==tmp_len){
                    tmp_output = tmp_a;
                    reverse(tmp_a.begin(), tmp_a.end());
                    output = tmp_a;
                    output.append(tmp_output);
                    // cout<<"output a "<<output<<endl;
                }
                else{
                //    cout<<"tmp b: "<< tmp_b<<endl; 
                   tmp_output = tmp_b.substr(1);
                   reverse(tmp_b.begin(), tmp_b.end());
                   output = tmp_b;
                   output.append(tmp_output);
                //    cout<<"output b "<<output<<endl;
                }
            }


        }
        
        return output;
    }

};
