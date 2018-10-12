class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(envelopes.size(),1);
        int res = 0;
        for(int i = s0;i < envelopes.size();i++){
            for(int j = i-1;j >= 0;j--){
                if(envelopes[j].first == envelopes[i].first)
                    continue;
                if(envelopes[j].second < envelopes[i].second){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};