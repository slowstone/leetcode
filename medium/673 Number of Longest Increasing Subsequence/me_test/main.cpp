class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> tmp(nums.size(),1);
        int finalres = 0;
        int res = 0;
        for(int i = 0;i < nums.size();i++){
        	for(int j = 0;j < i;j++){
        		if(nums[j] >= nums[i])
        			continue;
        		dp[i] = max(dp[j] + 1,dp[i]);
        		if(dp[j] + 1 > res){
        			res = dp[j] + 1;
        			tmp[i] = tmp[j];
        		}
        		else if(dp[j] + 1 == res)
        			tmp[i] = tmp[i] + tmp[j];
        	}
        }
        if(res == 1)
        	return nums.size();
        cout << "======" << endl;
        for(int i = nums.size()-1;i >= 0;i--){
        	cout << "(" << dp[i] << "-" << tmp[i] << ")" << " ";
        	if(dp[i] == res){
        		finalres = max(finalres,tmp[i]);
        		// break;
        	}
        }
        cout << endl;
        return finalres;
    }
};