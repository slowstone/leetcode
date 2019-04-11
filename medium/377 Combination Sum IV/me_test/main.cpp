class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j <= target;j++){
                if(j < nums[i])
                    continue;
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};