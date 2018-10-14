class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        int tmp = 0;
        for(int i = 1;i <= n;i++){
            if((tmp+1)*(tmp+1) == i){
                tmp++;
                dp[i] = 1;
                continue;
            }
            for(int j = tmp;j > 0;j--){
                dp[i] = min(dp[i],dp[i-j*j]+dp[j*j]);
            }
        }
        // cout << tmp << endl;
        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j*j <= i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        // cout << tmp << endl;
        return dp[n];
    }
};