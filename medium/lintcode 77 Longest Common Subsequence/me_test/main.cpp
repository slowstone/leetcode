class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        if(A.size() == 0 || B.size() == 0) return 0;
        vector<vector<int>> dp(A.size(),vector<int>(B.size()));
        for(int i = 0;i < A.size();i++){
            for(int j = 0;j < B.size();j++){
                if(i == 0 || j == 0){
                    dp[i][j] = max(A[i] == B[j] ? 1 : 0,dp[i][j]);
                    continue;
                }
                dp[i][j] = max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]+(A[i]==B[j] ? 1 : 0)));
            }
        }
        // for(auto d:dp){
        //     for(auto p:d)
        //         cout << p << " ";
        //     cout << endl;
        // }
        return dp[A.size()-1][B.size()-1];
    }
};