class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return 0;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),0));
        for(int i = 0;i < s.size();i++){
            for(int j = 0;j < t.size();j++){
                if(i < j)
                    continue;
                if(s[i] == t[j]){
                    if(j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] += dp[i-1][j-1];
                }
                if(i != 0)
                    dp[i][j] += dp[i-1][j];
            }
        }
        return dp[s.size()-1][t.size()-1];
    }
};