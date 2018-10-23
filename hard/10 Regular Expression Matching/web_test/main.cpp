class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        
        for(int j = 1;j <= n;j++){
            if(p[j-1] == '*')
                dp[0][j] = (j >= 2 ? dp[0][j-2] : 1);
        }
        
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    if(j == 1) dp[i][j] = 0;
                    else{
                        dp[i][j] = dp[i][j-2];
                        if(s[i-1] == p[j-2] || p[j-2] == '.')
                            dp[i][j] |= dp[i-1][j];
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[m][n];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        
        for(int j = 1;j <= n;j++){
            if(p[j-1] == '*')
                dp[0][j] = (j >= 2 ? dp[0][j-2] : 1);
        }
        
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    if(j == 1) dp[i][j] = 0;
                    else{
                        dp[i][j] = dp[i][j-2];
                        if(s[i-1] == p[j-2] || p[j-2] == '.')
                            dp[i][j] |= dp[i-1][j];
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[m][n];
    }
};