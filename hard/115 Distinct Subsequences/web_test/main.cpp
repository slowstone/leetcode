class Solution {
public:
    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(t.size()+1, vector<int>(s.size()+1, 0));
        
        for(int i=0; i<s.size(); i++) dp[0][i] = 1;
        
        for(int j=1; j<=s.size(); j++) {
            for(int i=1; i<=t.size(); i++) {
                int temp = 0;
                if(t[i-1]==s[j-1]) {
                    temp = dp[i-1][j-1];
                }
                dp[i][j] = dp[i][j-1] + temp; 
            }
        }
        
        return dp[t.size()][s.size()];
    }
};

class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        
        vector<int>dp(m + 1, 1);
        int diag = 0, tmp = 0;
        
        for(int i = 1; i <= n; ++i){
            diag = dp[0], dp[0] = 0;
            for(int j = 1; j <= m; ++j){
                tmp = dp[j];
                if(t[i - 1] == s[j - 1])
                    dp[j] = diag + dp[j - 1];
                else
                    dp[j] = dp[j - 1];
                
                diag = tmp;
            }
        }
        return dp[m];
    }
};