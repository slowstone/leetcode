class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]){
                totalProfit+=prices[i]-prices[i-1];
            }
        }
        return totalProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res= 0 ;
        int n = prices.size();
        if (n <= 1) return 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += ((prices[i] - prices[i-1]) > 0) ? (prices[i] - prices[i-1]) : 0;
        }
        return res;
    }
};

class Solution {
public:
    // decrease -> buy at last
    // increase -> sell at last
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) { return 0; }
        int b_price = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > b_price) {
                profit += prices[i] - b_price;
                b_price = prices[i];
            } else {
                b_price = prices[i];
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m < 2)
            return 0;
        int ans = 0;
        int q = -prices[0];
        for(int i = 1; i < m; i++){
            int t = ans;
            ans = max(ans, q+prices[i]);
            q = max(q, t-prices[i]);
        }

        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyday_index = 0;
        int sum = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[buyday_index] && i - buyday_index == 1) {
                buyday_index = i;
                continue;
            }

            if (prices[i] < prices[i - 1]) {
                sum += prices[i - 1] - prices[buyday_index];
                buyday_index = i;
                continue;
            }

            if (i == prices.size() - 1) {
                sum += prices[i] - prices[buyday_index];
            }            
        }

        return sum;
    }
};