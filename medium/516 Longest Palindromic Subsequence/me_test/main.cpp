class Solution {
private:
    int subfunction(string s,int left,int right){
        // cout << left << "-" << right << endl;
        if(left > right) return 0;
        if(left == right) return 1;
        if(s[left] == s[right]) return subfunction(s,left+1,right-1)+2;
        return max(subfunction(s,left+1,right),subfunction(s,left,right-1));
    }
public:
    int longestPalindromeSubseq(string s) {
        return subfunction(s,0,s.size()-1);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i = 0;i <= s.size();i++){
            for(int j = 0;j < s.size();j++){
                if(j+i >= s.size())
                    break;
                if(i == 0)
                    dp[j][j] = 1;
                else if(s[j] == s[j+i])
                    dp[j][j+i] = dp[j+1][j+i-1] + 2;
                else
                    dp[j][j+i] = max(dp[j+1][j+i],dp[j][j+i-1]);
            }
        }
        return dp[0][s.size()-1];
    }
};