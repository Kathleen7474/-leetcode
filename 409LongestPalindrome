class Solution {
public:
    int longestPalindrome(string s) {
        // s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
        // s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        // cout<< s<<endl;
        int output = 0;
        map<char, int> freq_map;
        int one_flag = 0;
        for (char ch : s)
            freq_map[ch]++;
        map<char, int>::iterator iter;
        for(iter = freq_map.begin(); iter != freq_map.end(); iter++){
            // cout<<iter->first<<" "<<iter->second<<endl;
            // cout<<"add "<< iter->second<<endl;
            output = output+((iter->second/2)*2);
            if (iter->second%2==1){
                if (one_flag == 0){
                output++;
                one_flag = 1;
                }
            }
        }
        return output;
    }
};
