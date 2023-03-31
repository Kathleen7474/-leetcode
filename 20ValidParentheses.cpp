class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        cout<<s.length()<<endl;
        for (int i = 0; i<s.length();i++){
            stk.push(s[i]);
        }
        stack <char> out;
        
        char tmp;
        for (int i = 0; i<s.length();i++){
            tmp = stk.top();
            // cout<<"hi"<<tmp<<endl;
            // cout<<"out size"<<out.size()<<endl;
            if(tmp=='}'||tmp==')'||tmp==']'){
                // cout<<"psuh"<<endl;
                out.push(tmp);
            }
            else{
                if(out.size()==0) return false;
                if(tmp=='['){
                    if(out.top()!=']')
                        return false;
                    out.pop();
                }
                else if(tmp=='('){
                    
                    if(out.top()!=')')
                        return false;
                    out.pop();
                }
                else if(tmp=='{'){
                    
                    if(out.top()!='}')
                        return false;
                    out.pop();
                }
            }
            stk.pop();
            
        }
        if(out.size()!=0)
            return false;
        return true;
    }
};
