class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int max_len = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]=='1')
            {
                dp[i][0] = 1;
                max_len = 1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]=='1')
            {
                dp[0][i] = 1;
                max_len = 1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                    max_len = max(max_len,dp[i][j]);
                }
            }
        }
        if(max_len==INT_MIN)
            return 0;
        return max_len*max_len;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)return 0;
        int m = matrix[0].size();
        if(m==0)return 0;
        vector<int>tmp(m,0);
        vector<vector<int>>bin(n,tmp);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    if(i>0&&j>0&&bin[i-1][j]!=0&&bin[i][j-1]!=0&&bin[i-1][j-1]!=0){
                        bin[i][j] = min(min(bin[i-1][j],bin[i][j-1]),bin[i-1][j-1])+1;
                    }else{
                        bin[i][j] = 1;
                    }
                    if(bin[i][j]>ans)ans=bin[i][j];
                }
            }
        }
        return ans*ans;
    }
};