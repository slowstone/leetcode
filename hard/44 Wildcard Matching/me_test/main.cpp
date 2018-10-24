class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
        for(int i = 0;i <= s.size();i++){
        	for(int j = 0;j <= p.size();j++){
        		if(j == 0)
        			continue;
        		if(i == 0){
        			if(p[j-1] == '*')
        				dp[i][j] = dp[i][j-1];
        			continue;
        		}
        		if(s[i-1] == p[j-1] || p[j-1] == '?')
        			dp[i][j] = dp[i-1][j-1];
        		if(p[j-1] == '*'){
        			dp[i][j] = dp[i][j-1] | dp[i-1][j];
        		}
        	}
        }
        return dp[s.size()][p.size()];
    }
};