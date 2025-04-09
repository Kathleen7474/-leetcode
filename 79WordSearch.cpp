class Solution {
    vector<vector<int>> looked;
    bool trace(vector<vector<char>>& board, string word, int i, int j){
        bool output = false;
        if(board[i][j]==word[0]){
            if(word.size()==1)
                return true;
            // 上
            if(i>0&&board[i-1][j]==word[1]&&looked[i-1][j]==0){
                looked[i-1][j] = 1;
                output = output|trace(board, word.substr(1), i-1, j);
                looked[i-1][j] = 0;
            }
            // 下
            if(i<board.size()-1&&board[i+1][j]==word[1]&&looked[i+1][j]==0){
                looked[i+1][j] = 1;
                output = output|trace(board, word.substr(1), i+1, j);
                looked[i+1][j] = 0;
            }
            // 左
            if(j>0&&board[i][j-1]==word[1]&&looked[i][j-1]==0){
                looked[i][j-1] = 1;
                output = output|trace(board, word.substr(1), i, j-1);
                looked[i][j-1] = 0;
            }
            // 右
            if(j<board[0].size()-1&&board[i][j+1]==word[1]&&looked[i][j+1]==0){
                looked[i][j+1] = 1;
                output = output|trace(board, word.substr(1), i, j+1);
                looked[i][j+1] = 0;
            }
        }
        return output;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        looked.resize(board.size()); // 設定外層大小
        for (int i = 0; i < board.size(); ++i) {
            looked[i].resize(board[0].size(), 0); // 設定內層大小並初始化為 0

        }
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                bool output = false;
                if(board[i][j]==word[0]){
                    looked[i][j] = 1;
                    if(word.size()==1)
                        return true;
                    // 上
                    if(i>0&&board[i-1][j]==word[1]){
                        looked[i-1][j] = 1;
                        output = output|trace(board, word.substr(1), i-1, j);
                        looked[i-1][j] = 0;
                    }
                    // 下
                    if(i<board.size()-1&&board[i+1][j]==word[1]){
                        looked[i+1][j] = 1;
                        output = output|trace(board, word.substr(1), i+1, j);
                        looked[i+1][j] = 0;
                    }
                    // 左
                    if(j>0&&board[i][j-1]==word[1]){
                        looked[i][j-1] = 1;
                        output = output|trace(board, word.substr(1), i, j-1);
                        looked[i][j-1] = 0;
                    }
                    // 右
                    if(j<board[0].size()-1&&board[i][j+1]==word[1]){
                        looked[i][j+1] = 1;
                        output = output|trace(board, word.substr(1), i, j+1);
                        looked[i][j+1] = 0;
                    }
                    looked[i][j] = 0;
                }
                if(output)
                    return true;
            }
        }
        return false;
    }
};
