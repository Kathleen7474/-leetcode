#include <algorithm>
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxprod = 0;
        vector<int> mask(words.size(),0);
        for(int i = 0;i<words.size();i++){
            for(auto c:words[i]){
                mask[i] |= 1<<(c - 'a');
            }
        }
        for(int i = 0;i<words.size();i++){
            for(int j = i+1;j<words.size();j++){
                if((mask[i]&mask[j])==0){
                    int prod = words[i].size()*words[j].size();
                    maxprod = std::max(maxprod, prod);
                }
            }
        }
        return maxprod;
    }
};
