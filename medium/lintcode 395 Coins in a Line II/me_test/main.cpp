class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if(values.size() < 1) return 0;
        vector<int> dp(values.size()+1,0);
        dp[values.size()] = 0;
        dp[values.size()-1] = values[values.size()-1];
        int sum = dp[values.size()-1];
        for(int i= values.size()-2;i >=0;i--){
        	sum += values[i];
        	dp[i] = max(sum - dp[i+1],sum - dp[i+2]);
        }
        // for(auto d:dp)
        //     cout << d << " ";
        // cout << endl << sum << endl;
        return sum-dp[0] < dp[0];
    }
};

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if(values.size() < 1) return 0;
        vector<int> dp(values.size()+1,0);
        dp[values.size()] = 0;
        dp[values.size()-1] = values[values.size()-1];
        for(int i= values.size()-2;i >=0;i--){
            dp[i] = max(-dp[i+1],-dp[i+2]+values[i+1])+values[i];
        }
        // for(auto d:dp)
        //     cout << d << " ";
        // cout << endl;
        return dp[0] >= 0;
    }
};