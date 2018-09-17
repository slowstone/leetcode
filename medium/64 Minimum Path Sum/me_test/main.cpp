class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 && j == 0)
                    continue;
                int sum = INT_MAX;
                int ii = i - 1;
                int jj = j - 1;
                if(ii >= 0)
                    sum = min(sum,grid[i][j] + grid[ii][j]);
                if(jj >= 0)
                    sum = min(sum,grid[i][j] + grid[i][jj]);
                grid[i][j] = sum;
            }
        }
        return grid[m-1][n-1];
    }
};