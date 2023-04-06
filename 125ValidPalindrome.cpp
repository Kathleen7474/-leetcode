class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        transform(s.begin(),s.end(),s.begin(),::tolower);

        string s_1;
        
        for (int i = 0;i<s.size();i++){
            s_1.push_back(s[s.size()-i-1]);
            cout<<i<<endl;
        }
        cout<<s<<endl;
        cout<<s_1<<endl;
        if(s_1==s)
            return true;
        return false;
    }
};
