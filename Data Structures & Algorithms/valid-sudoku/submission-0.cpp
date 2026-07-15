class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, col, box;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if(row[i].find(board[i][j]) != row[i].end()) return false;
                if(col[j].find(board[i][j]) != col[j].end()) return false;
                int b = (j/3) * 10 + (i/3);
                if(box[b].find(board[i][j]) != box[b].end()) return false;
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[b].insert(board[i][j]);
            }
        }
        return true;
    }
};
