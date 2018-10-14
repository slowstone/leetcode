class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if(pages.size() == 0 || k == 0) return 0;
        vector<vector<int>> dp(pages.size(),vector<int>(k,INT_MAX));
        int res = INT_MAX;
        for(int i = 0;i < pages.size();i++){
        	for(int t = 0;t < k;t++){
        		if(t == 0){
        			dp[i][t] = i == 0 ? pages[i] : dp[i-1][0] + pages[i];
        			continue;
        		}
        		for(int j = 0;j < i;j++){
        			int cost = max(dp[j][t-1],dp[i][0]-dp[j][0]);
        			dp[i][t] = min(cost,dp[i][t]);
        		}
        	}
        }
        for(int i = 0;i < k;i++)
        	res = min(res,dp[pages.size()-1][i]);
        return res;
    }
};