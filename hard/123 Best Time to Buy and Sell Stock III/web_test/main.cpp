class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profits(3, 0), bought(3,INT_MIN);
        for(int i:prices){
            for(int j = profits.size()-1; j>=0; --j){
                bought[j] = max(profits[j]-i, bought[j]);
                if(j)   profits[j] = max(profits[j], bought[j-1]+i);
            }
        }
        return *max_element(profits.begin(), profits.end());
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } else {
            int K = 2;
            int maxProfit = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int k = 1; k <= K; ++k) {
                int tmpMax = f[k-1][0] - prices[0];
                for (int i = 1; i < prices.size(); ++i) {
                    f[k][i] = max(f[k][i-1], prices[i] + tmpMax);
                    tmpMax = max(tmpMax, f[k-1][i] - prices[i]);
                    maxProfit = max(f[k][i], maxProfit);
                }
            }
            return maxProfit;
        }
        
    }
};