class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0};
        bool col[9][10] = {0};
        bool box[9][10] = {0};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int digit = board[i][j] - '0';
                    row[i][digit] = 1;
                    col[j][digit] = 1;
                    box[(j/3) + (i/3)*3][digit] = 1;
                }
            }
        }
        bool flag = false;
        backtrack(board, row, col, box, 0, 0, flag);
    }

    void backtrack(vector<vector<char>>& board, bool row[9][10], bool col[9][10], bool box[9][10], int r, int c, bool& flag){
        if(c >= 9){
            c = 0;
            r++;
        }
        if(r >= 9){
            flag = true;
            return;
        }

        if(board[r][c] != '.'){
            return backtrack(board, row, col, box, r, c+1, flag);
        }

        for(int i = 1; i <= 9; i++){
            if(row[r][i] || col[c][i] || box[(c/3)+(r/3)*3][i]) continue;

            board[r][c] = '0' + i;
            row[r][i] = 1;
            col[c][i] = 1;
            box[(c/3)+(r/3)*3][i] = 1;
            
            backtrack(board, row, col, box, r, c + 1, flag);

            if(flag == true) return;

            board[r][c] = '.';
            row[r][i] = 0;
            col[c][i] = 0;
            box[(c/3)+(r/3)*3][i] = 0;
        }
    }

};