class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool PredictTheWinner(vector<int> &values) {
        // write your code here
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),0));
        for(int i = 0;i < values.size();i++){
            for(int j = 0;j + i < values.size();j++){
                if(i == 0){
                    dp[j][j] = values[j];
                    continue;
                }
                dp[j][j+i] = max(-dp[j+1][j+i]+values[j],-dp[j][j+i-1]+values[j+i]);
            }
        }
        // for(auto d:dp){
        //     for(auto p:d)
        //         cout << p << " ";
        //     cout << endl;
        // }
        return dp[0][values.size()-1] >= 0;
    }
};