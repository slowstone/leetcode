class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> tmp(prices.size(),0);
        // int bprices = prices[0];
        int res = 0;
        int tmp = 0;
        bool flag = false;
        for(int i = 1;i < prices.size();i++){
            int sprices = prices[i] - prices[i-1];
            if(sprices > 0){
            	res += sprices;
            	tmp = sprices;
            	flag = true;
            }
            if(sprices < 0 && flag){
            	res -= tmp;
            	flag = false;
            }
            // cout << bprices << " " << sprices << " " << res << endl;
        }
        return res+tmp;
    }           
};