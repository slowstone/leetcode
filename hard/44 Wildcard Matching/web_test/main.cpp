class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, p_star = -1, s_star = -1;
        while (i<s.size()) {
            if (s[i] == p[j] || p[j]=='?') {
                i++; j++;
            } else if (p[j] == '*') {
                s_star = i;
                p_star = j++;
            } else if (p_star != -1) {
                i = s_star++;
                j = p_star + 1;
            } else {
                return false;
            }
        }
        while (j<p.size() && p[j] == '*') {
            j++;
        }
        return j == p.size();
    }
};

class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<bool> e(n+1, false);
        vector<vector<bool>> b(m+1, e);
        
        b[0][0] = true;
        
        for (int i = 1; i<=n;i++) {
            if (p[i-1] == '*') {
                b[0][i] = b[0][i-1];
            }
        }
        
        for (int i = 1; i <= m;i++) {
            for(int j=1; j <=n; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    b[i][j] = b[i-1][j-1]; 
                } else if(p[j-1] == '*') {
                    b[i][j] = b[i-1][j] || b[i][j-1] || b[i-1][j-1];
                } else {
                    b[i][j]=false;
                }
            }
    
        }
        
        return b[m][n];
        
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        //in case p[0] = '*'
        for (int j = 1; j <= p.size(); j++){
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
            
        for (int i = 0; i <= s.size(); i++){
            for (int j = 1; j <= p.size(); j++){
                if ((p[j-1] == '?' || p[j-1] == s[i-1]) && i > 0) 
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*' && i > 0)
                    //'*' : matches empty sequence or any sequence.
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
        return dp[s.size()][p.size()];
    }
};
