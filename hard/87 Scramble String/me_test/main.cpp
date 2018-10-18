class Solution {
private:
    vector<vector<vector<int>>> dp;
	bool compare(string s1, string s2, int left1,int left2,int len){
		// cout << left1 << " " << left2 << " " << len << endl;
        if(dp[left1][left2][len] == -1){
            if(len == 0){
                dp[left1][left2][len] = 1;
            }
            else if(len == 1){
                dp[left1][left2][len] = (s1[left1] == s2[left2]);
            }
            else if(len == 2){
                int right1 = left1 + len - 1;
                int right2 = left2 + len - 1;
                dp[left1][left2][len] = (s1[left1] == s2[left2] && s1[right1] == s2[right2]) 
                                            || 
                                        (s1[right1] == s2[left2] && s1[left1] == s2[right2]);
            }
            else{
                for(int i = 1;i < len;i++){
                    dp[left1][left2][len] = (compare(s1,s2,left1,left2,i) 
                                                && compare(s1,s2,+i,left2+i,len-i)) 
                                            || 
                                                (compare(s1,s2,left1,left2+len-i,i) 
                                                && compare(s1,s2,left1+i,left2,len-i));
                    if(dp[left1][left2][len] == 1){
                        cout << dp[left1][left2][len] << endl;
                        return dp[left1][left2][len] == 1;   
                    }
                }
            }
        }
        cout << dp[left1][left2][len] << endl;
		if(dp[left1][left2][len] == 1)
            return true;
        if(dp[left1][left2][len] == 0)
            return false;
	}
public:
    bool isScramble(string s1, string s2) {
        // cout << "======" << s1.size() << " " << s2.size() << endl;
        if(s1.size() != s2.size()) return false;
        dp = vector<vector<vector<int>>>(s1.size(),vector<vector<int>>(s1.size(),vector<int>(s1.size()+1,-1)));
    	compare(s1,s2,0,0,s1.size());
    	return dp[0][0][s1.size()];
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<bool>>> dp = 
                vector<vector<vector<bool>>>(n,vector<vector<bool>>(n,vector<bool>(n+1,false)));
        for(int len = 1;len <= n;len++){
            for(int i = 0;i+len <= n;i++){
                for(int j = 0;j+len <= n;j++){
                    if(len == 1)
                        dp[i][j][len] = s1[i] == s2[j];
                    for(int k = 1;k < len;k++){
                        dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                        // if(dp[i][j][k] && dp[i+k][j+k][len-k]){
                        //     dp[i][j][len] = true;
                        //     break;
                        // }
                        // if(dp[i][j+len-k][k] && dp[i+k][j][len-k]){
                        //     dp[i][j][len] = true;
                        //     break;
                        // }
                        if(dp[i][j][len]) break;
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};