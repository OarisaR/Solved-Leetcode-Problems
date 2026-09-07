/*
- 4 directions to move
- start with the cell that matches first letter of string
- once a letter is used, mark it to avoid returning it to tht cell

*/

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool find(vector<vector<char>>& board, int i, int j, int idx,
              string& word) {
        if (idx == word.size())
            return true; // found all
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '*')
            return false;
        if (board[i][j] != word[idx])
            return false;

        
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {

            int newi = i + dx[k];
            int newj = j + dy[k];
            if (find(board, newi, newj, idx + 1, word))
                return true;

        }
        board[i][j] = tmp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};