class Solution {
public:
    int minDistance(string word1, string word2) {
    	if(word1.size() == 0 || word2.size() == 0)
    		return word1.size() == 0 ? (word2.size() == 0 ? 0 : word2.size()) : word1.size();
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,INT_MAX));
        for(int i = 0;i <= word1.size();i++){
        	for(int j = 0;j <= word2.size();j++){
        		if(i == 0)
        			dp[i][j] = j;
        		else if(j == 0)
        			dp[i][j] = i;
        		else{
        			if(word1[i-1] == word2[j-1])
        				dp[i][j] = dp[i-1][j-1]; // not change
        			else
        				dp[i][j] = dp[i-1][j-1]+1; // change
        			dp[i][j] = min(dp[i][j],dp[i-1][j]+1); //delete
        			dp[i][j] = min(dp[i][j],dp[i][j-1]+1); // add
        		}
        	}
        }
        return dp[word1.size()][word2.size()];
    }
};