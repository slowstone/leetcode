class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i <= target;i++){
            for(int j = 0;j < nums.size();j++){
                if(i < nums[j])
                    continue;
                dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};

// top down
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> history;
        return helper(nums, target, history);
    }
    
    int helper(vector<int> &nums, int residual, unordered_map<int, int> &history){
        if(residual == 0) return 1;
        if(history.find(residual) != history.end()) return history[residual];
        
        int res = 0;
        // this is the key step to guarantee that we have all the combinations: always start from nums[0]
        for(int num:nums){
            if(num <= residual) res += helper(nums, residual - num, history);
        }
        history[residual] = res;
        return res;
    }
};