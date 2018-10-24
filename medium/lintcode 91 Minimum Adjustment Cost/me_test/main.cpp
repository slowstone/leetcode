class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
        vector<vector<int>> dp(2,vector<int>(101,0));
        int res = INT_MAX;
        int ndp = 0;
        int odp = 1;
        for(int i = 0;i < A.size();i++){
            ndp = odp;
            odp = 1 - ndp;
            for(int j = 1;j <= 100;j++){
                dp[ndp][j] = INT_MAX;
            }
            for(int j = 1;j <= 100;j++){
                if(dp[odp][j] == INT_MAX)
                    continue;
                for(int k = j - target < 1 ? 1 : j - target;k <= j + target && k <= 100;k++){
                    dp[ndp][k] = min(dp[ndp][k],dp[odp][j] + abs(k-A[i]));
                }
            }
        }
        for(int i = 1;i <= 100;i++)
            res = min(res,dp[ndp][i]);
        return res;
    }
};