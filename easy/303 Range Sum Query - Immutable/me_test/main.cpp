class NumArray {
private:
    vector<vector<int *>> dp;
public:
    NumArray(vector<int> nums) {
        vector<int> tmp;
        int sum = 0;
        for(auto n:nums){
            sum += n;
            tmp.push_back(n);
            dp.push_back(tmp);
            tmp.pop_back();
        }
    }
    
    int sumRange(int i, int j) {
        int d = j-i;
        if(d < dp[i].size()){
            return dp[i][d];
        }
        for(int k = dp[i].size();k <= d;k++){
            dp[i].push_back(dp[i][k-1] + dp[i+k][0]);
        }
        return dp[i][d];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> nums) {
        dp = vector<int>(nums.size()+1,0);
        dp[0] = 0;
        for(int i = 1;i <= nums.size();i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */