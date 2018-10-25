class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        vector<vector<int>> dp(target+1,vector<int>(k+1,0));
        dp[0][0] = 1;
        for(int i = 0;i < A.size();i++){
            for(int j = target;j >= A[i];j--){
                for(int n = k;n >= 1;n--)
                    dp[j][n] += dp[j-A[i]][n-1];
            }
            // cout << "=======" << endl;
            // for(auto d:dp){
            //     for(auto p:d)
            //         cout << p << " ";
            //     cout << endl;
            // }
        }
        return dp[target][k];
    }
};