class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int btmp = prices[0];
        int stmp = prices[0];
        int res = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] <= btmp){
                btmp = prices[i];
                stmp = btmp;
            }
            else{
                stmp = prices[i];
            }
            res = max(stmp-btmp,res);
        }
        return res;
    }
};