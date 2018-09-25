class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (!coins.size()) return -1;
        sort(coins.begin(), coins.end());
        int ret = -1;
        find(coins, coins.size() - 1, amount, 0, ret);
        return ret;
    }
    
    void find(vector<int> & coins, int index, int amount, int cur, int & ret)
    {
        if (index < 0 || amount < 0) return;
        if (amount % coins[index] == 0)
        {
            int cnt = amount / coins[index] + cur;
            ret = ret == -1 ? cnt : min(ret, cnt);
            return;
        }
        
        for (int i = amount / coins[index]; i >= 0; i--)
        {
            if (ret != -1 && cur + i >= ret - 1) break;
            find(coins, index - 1, amount - i * coins[index], cur + i, ret);
        }
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    int res = INT_MAX;
     
    helper(res, coins, amount, coins.size() - 1, 0);
     
    return res == INT_MAX ? -1 : res;
}
private:
	void helper(int& res, vector<int>& coins, int target, int idx, int count){
	    if (idx < 0) return;
	    if (target % coins[idx] == 0){
	        res = min( res, count + target/coins[idx] );
	        return;
	    }
	     
	    for (int i=target/coins[idx]; i>=0; --i){
	        if (count + i >= res - 1) break;    // pruing
	        helper(res, coins, target - i * coins[idx], idx - 1, count + i);
	    }
	}
};