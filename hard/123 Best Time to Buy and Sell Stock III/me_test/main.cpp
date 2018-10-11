class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 5;
        int res = 0;
        vector<vector<int>> dp(prices.size(),vector<int>(k,0));
        for(int i = 1;i < prices.size();i++){
            for(int j = 1;j < k;j++){
                int profit = prices[i] - prices[i-1];
                if(j%2 == 0){
                    dp[i][j] = max(dp[i-1][j],max(dp[i-1][j-1]+profit,dp[i-1][j-1]));
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + profit;
                }
                if(i == prices.size()-1)
                    res = max(dp[i][j],res);
            }
        }
        // cout << "============" << endl;
        // for(auto d:dp){
        //     for(auto p:d){
        //         cout << p << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 5;
        int res = 0;
        vector<int> dp(k,0);
        for(int i = 1;i < prices.size();i++){
            for(int j = k-1;j > 0;j--){
                int profit = prices[i] - prices[i-1];
                // if(j%2 == 0){
                //     dp[j] = max(dp[j],max(dp[j-1]+profit,dp[j-1]));
                // }
                // else{
                //     dp[j] = max(dp[j],dp[j-1]) + profit;
                // }
                dp[j] = j%2 != 0 ? max(dp[j-1],dp[j])+profit : max(dp[j-1]+profit,max(dp[j-1],dp[j]));
                if(i == prices.size()-1)
                    res = max(dp[j],res);
            }
        }
        return res;
    }
};