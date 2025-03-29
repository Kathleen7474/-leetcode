class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> m2;
        for(int i = 0;i<size(s);i++){
            // 不存在於map中
            if(m.find(s[i])==m.end()&&m2.find(t[i])==m2.end()){
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }else if(m[s[i]] != t[i]||m2[t[i]] != s[i]){
                return false;
            }
        }
        return true; 
    }
};
