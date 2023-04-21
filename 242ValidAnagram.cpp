class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> anagram_map;
        for (int i = 0;i<s.length();i++){
            cout<<s[i]<<endl;
            anagram_map[s[i]]++;
            cout<<anagram_map[s[i]]<<endl;
        }
        for (int i = 0;i<t.length();i++){
            cout<<t[i]<<endl;
            anagram_map[t[i]]--;
            cout<<anagram_map[t[i]]<<endl;
            if(anagram_map[t[i]]<0)
                return false;
        }
        for (int i = 0;i<s.length();i++){
            if(anagram_map[s[i]]!=0)
                return false;
        }
        return true;
    }
};
