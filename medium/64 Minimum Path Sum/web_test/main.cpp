class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int minSum[m][n];
        minSum[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) {
            minSum[i][0] = minSum[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++) {
            minSum[0][j] = minSum[0][j-1] + grid[0][j];
        }
        
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                minSum[i][j] = min(minSum[i-1][j], minSum[i][j-1]) + grid[i][j];
            }
        }
        
        
        return minSum[m-1][n-1];
        
    }