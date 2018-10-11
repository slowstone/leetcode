class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0;
        if(k > prices.size()/2){
            for(int i = 1;i < prices.size();i++){
                int sprices = prices[i] - prices[i-1];
                res += sprices > 0 ? sprices:0;
            }
            return res;
        }
        k = 2*k+1;
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