class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res(board.size(),vector<int>(board[0].size(),0));
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                int ii = i - 1;
                int jj = j - 1;
                int iii = i + 1;
                int jjj = j + 1;
                vector<int> cellstate(2,0);
                if(ii >= 0 && jj >= 0)
                    cellstate[board[ii][jj]]++;
                if(ii >= 0)
                    cellstate[board[ii][j]]++;
                if(ii >= 0 && jjj < board[0].size())
                    cellstate[board[ii][jjj]]++;
                if(jj >= 0)
                    cellstate[board[i][jj]]++;
                if(jjj < board[0].size())
                    cellstate[board[i][jjj]]++;
                if(iii < board.size() && jj >= 0)
                    cellstate[board[iii][jj]]++;
                if(iii < board.size())
                    cellstate[board[iii][j]]++;
                if(iii < board.size() && jjj < board[0].size())
                    cellstate[board[iii][jjj]]++;
                if(board[i][j]){
                    if(cellstate[1] == 2 || cellstate[1] == 3)
                        res[i][j] = 1;
                }
                else{
                    if(cellstate[1] == 3)
                        res[i][j] = 1;
                }
            }
        }
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                board[i][j] = res[i][j];
            }
        }
    }
};