class Solution {
public:
int rows,cols;
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int pos){
        if(i < 0 || i >= rows || j < 0 || j >= cols) return false;
        char ch = board[i][j];

        if(ch == '#') return false;
        if(pos == word.size() - 1) return word[pos] == ch;

        board[i][j] = '#';

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        if(ch == word[pos]){
            for(int k = 0; k < 4; ++k){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(dfs(nr,nc, board, word, pos + 1)) return true;
            }
        }
    
        board[i][j] = ch;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(dfs(i,j,board,word,0)) return true;
            }
        }
    
        return false;
    }
};
