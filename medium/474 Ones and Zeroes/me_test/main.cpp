class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i <= strs.size();i++){
            int z = 0,o = 0;
            for(auto c:strs[i-1]){
                if(c == '0')
                    z++;
                if(c == '1')
                    o++;
            }
            for(int j = m;j >= z;j--){
                for(int k = n;k >= o;k--){
                    dp[j][k] = max(dp[j][k],dp[j-z][k-o]+1);
                }
            }
            // for(auto d:dp){
            //     for(auto p:d)
            //         cout << p << " ";
            //     cout << endl;
            // }
        }
        return dp[m][n];
    }
};