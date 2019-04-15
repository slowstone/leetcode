class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,0);
        vector<int> ptr(primes.size(),0);
        dp[0] = 1;
        for(int i = 1;i < n;i++){
            int cur = -1;
            for(int j = 0;j < primes.size();j++){
                while(primes[j]*dp[ptr[j]] <= dp[i-1])
                    ptr[j]++;
                if(cur == -1 || primes[cur]*dp[ptr[cur]] > primes[j]*dp[ptr[j]])
                    cur = j;
            }
            dp[i] = primes[cur] * dp[ptr[cur]];
            ptr[cur]++;
        }
        return dp[n-1];
    }
};