class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0;
        int cur = 0;
        for(int g: gain){
            cur = cur + g;
            if(cur>max_alt)
                max_alt = cur;
        }
        return max_alt;
    }
};
