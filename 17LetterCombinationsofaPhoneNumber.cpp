class Solution {
    vector<string> output;
    string tmp;
    unordered_map <char, string> map{{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6',"mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    void lComb(string digits){
        if(digits.size()==0){
            output.push_back(tmp);
            return;
        }
        // for(char d: digits){
        char d = digits[0];
            string candi = map[d];
            for (char c: candi){
                tmp.push_back(c);
                lComb(digits.substr(1));
                tmp.pop_back();
            }
    }


public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        lComb(digits);
        return output;
    }
};
