class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0); // ASCII map，紀錄 t 中每個字元需要的數量
        int count = t.length();       // 要找到的總字元數
        int start = 0, end = 0;       // 雙指標
        int minLen = INT_MAX;         // 最小子字串長度
        int startIndex = 0;           // 最小子字串的起始位置

        // 初始化：把 t 中每個字元的需求加進 map 裡
        for (char c : t) {
            map[c]++;
        }

        // 滑動視窗
        while (end < s.length()) {
            char curChar = s[end];

            // 如果這個字元是需要的，就讓 count 減少
            if (map[curChar] > 0) {
                count--;
            }

            // 無論是不是需要的字元，都要把它用掉
            // 重點在這裡，所以後面判斷才不會出界
            map[curChar]--;

            end++; // 移動右邊界

            // 當 count == 0 表示目前的視窗包含所有 t 的字元
            while (count == 0) {
                // 嘗試更新最小長度
                if (end - start < minLen) {
                    minLen = end - start;
                    startIndex = start;
                }

                char leftChar = s[start];

                // 我們要把左邊的字元移出視窗（縮小範圍）
                map[leftChar]++;
                // 如果這個字元是 t 裡面要的，而且現在缺了，就讓 count++
                if (map[leftChar] > 0) {
                    count++;
                }

                start++; // 移動左邊界
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
