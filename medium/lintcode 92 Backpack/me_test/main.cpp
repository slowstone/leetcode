class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<int> dp(m+1,0);
        int res = 0;
        for(auto a:A){
            for(int i = m;i >= 0;i--){
                if(i < a)
                    break;
                dp[i] = max(dp[i],dp[i-a]+a);
            }
        }
        for(auto d:dp){
            // cout << d << " ";
            res = max(res,d);
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<bool> dp(m+1,false);
        dp[0] = true;
        for(auto a:A){
            for(int i = m;i >= 0;i--){
                if(i < a)
                    break;
                dp[i] = dp[i] || dp[i-a];
            }
        }
        for(int i = m;i >= 0;i--){
            if(dp[i])
                return i;
        }
    }
};