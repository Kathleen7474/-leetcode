class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stk;
        stack<char> t_stk;
        for(char c:s){
            if(c != '#')
                s_stk.push(c);
            else{
                if(!s_stk.empty())
                    s_stk.pop();
            }  
        }
        for(char c:t){
            if(c != '#')
                t_stk.push(c);
            else{
                if(!t_stk.empty())
                    t_stk.pop();
            }
        }
        string fs, ft;
        while(!s_stk.empty()){
            fs.push_back(s_stk.top());
            s_stk.pop();
        }
        while(!t_stk.empty()){
            ft.push_back(t_stk.top());
            t_stk.pop();
        }
        return (fs==ft);
    }
};
