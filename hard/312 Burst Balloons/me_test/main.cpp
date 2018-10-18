class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	if(nums.size() < 1) return 0;
    	vector<int> tmp{1};
    	tmp.insert(tmp.end(),nums.begin(),nums.end());
    	tmp.push_back(1);
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,0));
        for(int len = 1;len <= nums.size();len++){
        	for(int i = 1;i + len <= nums.size()+1;i++){
        		int j = i + len - 1;
        		for(int k = i;k <= j;k++){
        			int cur = dp[i][k-1] + dp[k+1][j];
        			cur = tmp[i-1] * tmp[j+1] * tmp[k] + cur;
        			dp[i][j] = max(dp[i][j],cur);
        		}
        	}
        }
        return dp[1][nums.size()];
    }
};