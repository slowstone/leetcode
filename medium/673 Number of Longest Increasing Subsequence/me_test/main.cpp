class ResType{
public:
    int len;
    int num;
    ResType(){
        this->len = 0;
        this->num = 0;
    }
    ResType(int len,int num){
        this->len = len;
        this->num = num;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<ResType> dp(nums.size(),ResType(1,1));
        int res = 0,num = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[j] < nums[i]){
                    if(dp[j].len >= dp[i].len){
                        dp[i].len = dp[j].len + 1;
                        dp[i].num = dp[j].num;
                    }
                    else if(dp[j].len == dp[i].len-1)
                        dp[i].num += dp[j].num;
                }
            }
            if(res < dp[i].len){
                res = dp[i].len;
                num = dp[i].num;
            }
            else if(res == dp[i].len)
                num += dp[i].num;
        }
        // cout << "===" << endl;
        // for(auto nn:dp){
        //     cout << nn.len << "-" << nn.num << " ";
        // }
        // cout << endl;
        return num;
    }
};