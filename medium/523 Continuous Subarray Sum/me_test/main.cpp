class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // cout << endl;
        // cout << "----" << endl;
        for(int i = 2;i <= nums.size();i++){
            for(int j = 0;j <= nums.size()-i;j++){
                int sums = 0;
                for(int k = 0;k < i;k++)
                    sums += nums[j+k];
                // cout << sums << " ";
                if(k == 0){
                    if(sums == 0)
                        return true;
                }
                else{
                    if(sums %k == 0)
                        return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> dp(nums);
        for(int i = 2;i <= nums.size();i++){
            for(int j = 0;j <= nums.size()-2;j++){
                dp[j] = dp[j] + nums[j+i-1];
                if(k == 0){
                    if(dp[j] == 0)
                        return true;
                }
                else{
                    if(dp[j] %k == 0)
                        return true;
                }
            }
        }
        return false;
    }
};