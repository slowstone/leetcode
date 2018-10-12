class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,0));
        int res = 0;
        for(int i = 1;i < prices.size();i++){
            int profit = prices[i] - prices[i-1];
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]+profit);
            dp[i][2] = max(0,dp[i-1][1]+profit);
            res = max(res,dp[i][2]);
        }
        // cout << "========" << endl;
        // for(auto d:dp){
        //     for(auto p:d)
        //         cout << p << " ";
        //     cout << endl;
        // }
        return res;
    }
};