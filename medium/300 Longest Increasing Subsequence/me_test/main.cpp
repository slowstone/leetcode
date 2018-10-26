class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int res = 0;
        for(int i = 0;i < nums.size();i++){
        	for(int j = 0;j < i;j++){
        		if(nums[i] > nums[j])
        			dp[i] = max(dp[i],dp[j]+1);
        	}
        	res = max(res,dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{INT_MAX};
        for(int i = 0;i <nums.size();i++){
            int res = 0,left = 1,right = dp.size()-1;
            while(left <= right){
                int mid = (left + right)/2;
                // cout << i << " " << left <<" "<< mid <<" "<< right << endl;
                if(dp[mid] < nums[i]){
                    res = mid;
                    left = mid+1;
                }
                else if(dp[mid] > nums[i])
                    right = mid-1;
                else
                    break;
            }
            if(res+1 == dp.size())
                dp.push_back(nums[i]);
            else
                dp[res+1] = min(nums[i],dp[res+1]);
            // for(auto d:dp)
            //     cout << d << " ";
            // cout << endl;
        }
        return dp.size()-1;
    }
};