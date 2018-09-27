class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<vector<int>> restmp(m,vector<int>(n,0));
        int res = 0;
        // up
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                dp[i][j] = 0;
                if(grid[i][j] == 'W')
                    continue;
                dp[i][j] += grid[i][j] == '0' ? 0:1;
                if(i != 0)
                    dp[i][j] += dp[i-1][j];
                restmp[i][j] += grid[i][j] == 'E' ? 0:dp[i][j];
            }
        }
        // left
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                dp[i][j] = 0;
                if(grid[i][j] == 'W')
                    continue;
                dp[i][j] += grid[i][j] == '0' ? 0:1;
                if(j != 0)
                    dp[i][j] += dp[i][j-1];
                restmp[i][j] += grid[i][j] == 'E' ? 0:dp[i][j];
            }
        }
        //down
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                dp[i][j] = 0;
                if(grid[i][j] == 'W')
                    continue;
                dp[i][j] += grid[i][j] == '0' ? 0:1;
                if(i != m-1)
                    dp[i][j] += dp[i+1][j];
                restmp[i][j] += grid[i][j] == 'E' ? 0:dp[i][j];
            }
        }
        //right
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                dp[i][j] = 0;
                if(grid[i][j] == 'W')
                    continue;
                dp[i][j] += grid[i][j] == '0' ? 0:1;
                if(j != n-1)
                    dp[i][j] += dp[i][j+1];
                restmp[i][j] += grid[i][j] == 'E' ? 0:dp[i][j];
                res = max(restmp[i][j],res);
            }
        }
        // for(auto r:restmp){
        //     for(auto b:r){
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
};


class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        if(grid.size() == 0||grid[0].size() == 0) return 0;

        int row = grid.size();
        int col = grid[0].size();
        int r = 0;
        vector<int> c(col,0);
        int res = 0;

        for (int i = 0 ; i < row ; i ++ ) {

            for(int j = 0 ; j < col ; j ++ ){

                if(i == 0 || grid[i-1][j]=='W') {   
                    c[j] = 0;    
                    for(int k = i; k < row && grid[k][j]!='W'; ++k) {   
                        if(grid[k][j] == 'E')
                            c[j] ++;    
                    }  
                } 

                if(j == 0 || grid[i][j-1] == 'W'){
                    r = 0;
                    for(int k = j ; k < col && grid[i][k] != 'W'; ++k){
                        if(grid[i][k] == 'E'){
                            r++;
                        }
                    }
                }

                if(grid[i][j] == '0')  
                    res = max(res,r + c[j]);
            }
        }

        return res; 
    }
};