class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector< pair<int,int> > index{{1,1},{4,1},{7,1},{1,4},{1,7},{4,4},{4,7},{7,4},{7,7}};
        vector< pair<int,int> > cut{{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0;i < 9;i++){
            vector<bool> tmp1(10,0);
            vector<bool> tmp2(10,0);
            for(int j = 0;j < 9;j++){
                char cur = board[i][j];
                if(cur != '.'){
                    int k1 = int(cur - '0');
                    if(tmp1[k1])
                        return false;
                    tmp1[k1] = true;
                }
                cur = board[j][i];
                if(cur != '.'){
                    int k2 = int(cur - '0');
                    if(tmp2[k2])
                        return false;
                    tmp2[k2] = true;
                }
            }
        }
        for(auto i:index){
            vector<bool> tmp(10,0);
            for(auto c:cut){
                char cur = board[i.first+c.first][i.second+c.second];
                if(cur == '.')
                    continue;
                int k = int(cur - '0');
                if(tmp[k])
                    return false;
                tmp[k] = true;
            }
        }
        return true;
    }
};