class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        vector<vector<bool>> dp(s1.length()+1, vector<bool>(s2.length()+1,false));
        for(int i=0;i<=s1.length();i++) {
            for(int j=0;j<=s2.length();j++) {
                if(i==0 && j==0) {
                    dp[i][j]=true;
                }
                else if(i==0) {
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
                else if(j==0) {
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else {
                    dp[i][j]=(dp[i][j-1] && s2[j-1]==s3[i+j-1]) || (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        unordered_map<char, int> map;
        for(int i = 0; i < s1.length(); i++)
            map[s1[i]]++;
        for(int i = 0; i < s2.length(); i++)
            map[s2[i]]++;
        for(int i = 0; i < s3.length(); i++) {
            map[s3[i]]--;
            if(map[s3[i]] < 0)
                return false;
        }
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if((j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]))
                    dp[i][j] = true;
            }
        }
        return dp[s1.length()][s2.length()];
    }
};