class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        int res = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
                cout << dp[i][j] << " ";
                if(i != 0 && j != 0 && dp[i][j] != 0)
                    dp[i][j] = min(dp[i-1][j-1] + 1,min(dp[i][j-1]+1,dp[i-1][j]+1));
                res = max(res,dp[i][j]);
            }
            cout << endl;
        }
        cout << "-====-" << endl;
        for(auto d:dp){
            for(auto p:d)
                cout << p << " ";
            cout << endl;
        }
        return res*res;
    }
};