class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m){
        if(dp[i][j]) return dp[i][j];
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        int res = 1;
        for(auto d:dirs){
            int x = i + d[0];
            int y = j + d[1];
            if(x < 0 || x >= n || y < 0 || y >= m || matrix[i][j] >= matrix[x][y])
                continue;
            int cur_res = 1 + dfs(matrix, dp, x, y, n, m);
            res = max(cur_res,res);
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(m == 0) return 0;
        int res = 1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res = max(res,dfs(matrix, dp, i, j, n, m));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    int m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int res = 1;
        for(auto d:dirs){
            int x = i + d[0];
            int y = j + d[1];
            if(x < 0 || x >= n || y < 0 || y >= m || matrix[i][j] >= matrix[x][y])
                continue;
            int cur_res = 1 + dfs(matrix, x, y);
            res = max(cur_res,res);
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0) return 0;
        m = matrix[0].size();
        if(m == 0) return 0;
        int res = 1;
        dp.resize(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!dp[i][j])
                    res = max(res,dfs(matrix, i, j));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    int m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int res = 1;
        for(int k = 0;k < 4;k++){
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m || matrix[i][j] >= matrix[x][y])
                continue;
            int cur_res = 1 + dfs(matrix, x, y);
            res = max(cur_res,res);
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0) return 0;
        m = matrix[0].size();
        if(m == 0) return 0;
        int res = 1;
        dp.resize(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!dp[i][j])
                    res = max(res,dfs(matrix, i, j));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    int m;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int res = 1;
        for(int k = 0;k < 4;k++){
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m || matrix[i][j] >= matrix[x][y])
                continue;
            int cur_res = 1 + dfs(matrix, x, y);
            res = max(cur_res,res);
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0) return 0;
        m = matrix[0].size();
        int res = 1;
        dp.resize(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!dp[i][j])
                    res = max(res,dfs(matrix, i, j));
            }
        }
        return res;
    }
};