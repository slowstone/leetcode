class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> tmp(amount+1,INT_MAX);
        tmp[0] = 0;
        for(int i = 0;i < coins.size();i++){
            for(int j = 1;j <= amount;j++){
                if(j < coins[i])
                    continue;
                
                tmp[j] = min(tmp[j],tmp[j-coins[i]] == INT_MAX ? INT_MAX:tmp[j-coins[i]]+1);
            }
        }
        return tmp[amount] == INT_MAX ? -1:tmp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> tmp(amount+1,INT_MAX);
        tmp[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int j = 0;j < coins.size();j++){
                if(i < coins[j])
                    continue;
                tmp[i] = min(tmp[i],tmp[i-coins[j]] == INT_MAX ? INT_MAX:tmp[i-coins[j]]+1);
            }
        }
        return tmp[amount] == INT_MAX ? -1:tmp[amount];
    }
};