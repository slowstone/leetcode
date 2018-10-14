class Solution {
public:
    int minCut(string s) {
        const int aLen = s.length();
        if (aLen<=1) {
            return 0;
        }
        
        int i, j, aCuts[aLen+1];
        for (i=0; i<=aLen; ++i) {
            aCuts[i] = i-1;
        }
        
        for (i=1;i<aLen;i++) {
            for(j=0;(i-j)>=0 && (i+j)<aLen && s[i-j]== s[i+j]; ++j) { // odd-length substrings 
                aCuts[i+j+1] = min(aCuts[i+j+1], 1 + aCuts[i-j]);
            }
            for (j=0;(i-j-1)>=0 && (i+j)<aLen && s[i-j-1]== s[i+j]; ++j) { // even-length substrings
                aCuts[i+j+1] = min(aCuts[i+j+1], 1 + aCuts[i-j-1]);
            }
        }
        return aCuts[aLen];
    }
    
};

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n);
        vector<vector<bool>> P(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            int cut = i;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (i-j <= 1 || P[j+1][i-1])) {
                    P[j][i] = true;
                    cut = (j == 0) ? 0 : min(cut, dp[j-1] + 1);
                }
            }
            dp[i] = cut;
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        int C[n];
        bool P[n][n];
        for(int i=0;i<n;i++){
            C[i]=0;
            P[i][i]=true;
        }
        for(int d=2;d<=n;d++){
            for(int i=0;i<n-d+1;i++){
                int j=i+d-1;
                if(d==2) P[i][j]=(s[i]==s[j]);
                else P[i][j]=(s[i]==s[j])&&P[i+1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            if(P[0][i]) C[i]=0;
            else{
                C[i]=INT_MAX;
                for(int j=0;j<i;j++){
                    if(P[j+1][i]==true&&C[j]+1<C[i]) C[i]=1+C[j];
                }
            }
            
        }
        return C[n-1];
    }
};