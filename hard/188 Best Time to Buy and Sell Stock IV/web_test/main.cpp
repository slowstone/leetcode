class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int maxProfit = 0;
        if (k >= n / 2) {
            // if k >= n/2, then you can make maximum number of transactions.
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1])
                    maxProfit += prices[i] - prices[i-1];
            }
            return maxProfit;
        }
            
        vector<vector<int>> f(k+1, vector<int>(prices.size(), 0));
        for (int j = 1; j <= k; ++j) {
            int tmpMax = f[j-1][0] - prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                f[j][i] = max(f[j][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, f[j-1][i] - prices[i]);
                maxProfit = max(f[j][i], maxProfit);
            }
        }
        return maxProfit;
    }
};