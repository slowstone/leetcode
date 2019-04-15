class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int p_2 = 1;
        int p_3 = 1;
        int p_5 = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = min(dp[p_2]*2,min(dp[p_3]*3,dp[p_5]*5));
            if(dp[p_2] * 2 == dp[i]) p_2++;
            if(dp[p_3] * 3 == dp[i]) p_3++;
            if(dp[p_5] * 5 == dp[i]) p_5++;
        }
        return dp[n];
    }
};