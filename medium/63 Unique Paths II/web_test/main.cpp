class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if( grid.size() == 0 || grid[0].size() == 0) return false;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        dp[0] = 1;
        for( int i = 0; i < m; i++)
            for( int j = 0; j < n; j++)
                if( grid[i][j])
                    dp[j] = 0;
                else
                    dp[j] +=  (j > 0? dp[j-1]:0);
        return dp[n-1];
    }
};