class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int cur = 1;
        int row_start = 0, row_end = n-1, col_start = 0, col_end = n-1;
        while(cur <= n*n){
            for(int k = col_start; k <= col_end; k ++){
                ret[row_start][k] = cur ++ ;
            }
            row_start ++;
            for(int k = row_start; k <= row_end; k++){
                ret[k][col_end]=cur++;
            }
            col_end--;
            for(int k = col_end; k >= col_start; k --){
                ret[row_end][k] =cur++;
            }
            row_end --;
            for(int k = row_end; k >= row_start; k--){
                ret[k][col_start] = cur++;
            }
            col_start ++;
        }
        return ret;
    }
};