class Solution {
public:
    bool dfs(int i, int j, int k, int m, int n, string word, vector<vector<char>>& board) {
        if (k == word.length()) {
                return true;
            }
            
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (dfs(i + 1, j, k + 1,m, n, word, board) || dfs(i - 1, j, k + 1,m, n, word, board) || 
                dfs(i, j + 1, k + 1,m, n, word, board) || dfs(i, j - 1, k + 1,m, n, word, board)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0, m, n, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};

