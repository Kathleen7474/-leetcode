class Solution {
public:
    bool hasMatch(string s, string p) {
        int start_p = 0;
        int start_s = 0;
        int pass = 0;
        for (int i =0; i<p.size();i++){
            if (p[i]=='*')
                pass = i;
        }
        for (int i=0;i<s.size();i++){
            if(p[start_p]==s[i]){
                if (start_p==0) 
                    start_s = i;
                start_p++;
            }
            else if (p[start_p]=='*'){
                int tmp = start_p;
                tmp++;
                start_p++;
                for (int j=i;j<s.size();j++){
                    if (p[tmp] == s[j]){
                        i = j;
                        start_p++;
                        start_s = i;
                        break;
                    }
                }
                if (start_p == p.size())
                    return true;
            }
            else {
                cout<<"reset"<<endl;
            
                if (start_p>pass)
                    start_p = pass;
                else start_p = 0;
                i = start_s+1;
                start_s++;
                if (p[start_p]=='*'){
                    start_s = i+1;
                    int tmp = start_p;
                    tmp++;
                    start_p++;
                    
                    for (int j=i;j<s.size();j++){
                        if (p[tmp] == s[j]){
                            i = j;
                            start_p++;
                            start_s = i;
                            break;
                        }
                    }
                    if (start_p == p.size())
                        return true;
                }
                else if (p[start_p]==s[i]){
                    start_p++;
                }
            }

            if (start_p == p.size())
                return true;
            if (p[p.size()-1]=='*'&&start_p==p.size()-1) 
                return true;
            cout<<"i: "<<i<<" "<<s[i]<<endl;
            cout<<"start_p: "<<start_p<<endl;
            cout<<"start_s: "<<start_s<<endl;
        }
        
        return false;

    }
};
