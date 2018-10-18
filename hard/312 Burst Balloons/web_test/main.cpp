class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        
        for(int i=0;i<nums.size();i++) {
            dp[i][i]=(i-1<0?1:nums[i-1])*nums[i]*(i+1>=nums.size()?1:nums[i+1]);
        }
        
        int m=0;
        
        for(int j=1;j<nums.size();j++) {
            for(int i=0;i+j<nums.size();i++) {
                int m=0;
                for(int k=i;k<=i+j;k++) {
                    int temp=0;
                    if(k==i)
                        temp+=dp[i+1][i+j];
                    else if(k==i+j)
                        temp+=dp[i][i+j-1];
                    else
                        temp+=dp[i][k-1]+dp[k+1][i+j];
                    temp+=(i-1<0?1:nums[i-1])*nums[k]*(i+j+1>=nums.size()?1:nums[i+j+1]);
                    if(m<temp)
                        m=temp;
                }
                dp[i][i+j]=m;
            }
        }
        return dp[0].back();
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};

class Solution {
    // max coins by bursting nums[left: right]
    int max_coins(vector<int> & nums, int left, int right, vector<vector<int>> & coins) {
        if (left > right) {
            return 0;
        }
        if (coins[left][right] >= 0) {
            return coins[left][right];
        }
        int max_profit = 0;
        // select the balloon to burst last 
        for (int i = left; i <= right; i++) {
            int left_neighbor = left - 1 >= 0? nums[left - 1]: 1;
            int right_neighbor = right + 1 < nums.size() ? nums[right + 1]: 1;
            auto cur_coins = left_neighbor * nums[i] * right_neighbor 
                + max_coins(nums, left, i - 1, coins)
                + max_coins(nums, i + 1, right, coins);
            max_profit = max(max_profit, cur_coins);
        }
        return (coins[left][right] = max_profit);
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if (!size) {
            return 0;
        }
        // as nums[i] >= 0, we use -1 to indicate "uncomputed"
        vector<vector<int>> coins(size, vector<int>(size, -1));
        return max_coins(nums, 0, size - 1, coins);
    }
};