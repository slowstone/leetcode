class Solution {
public:
    bool isMatch(string s, string p) {
        int j = 0,i = 0;
        char pre = '!';
        while(i < s.size() || j < p.size()){
        	if(s[i] == p[j] || p[j] == '.'){
        		i++;
        		j++;
        		pre = p[j];
        	}
        	else if(p[j] == '*'){
        		if(s[i] == pre || pre == '.'){
        			i++;
        		}
        		else{
        			i++;
        			j++;
        		}
        	}
        	else{
        		return false;
        	}
        }
        if(i != s.size())
        	return false;
        if(j != p.size() || j != p.size()-1)
        	return false;
        return true;
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
       	for(int i = 0;i <= s.size();i++){
       		for(int j = 0;j <= p.size();j++){
       			if(j == 0)
       				continue;
       			if(i == 0){
       				if(p[j-1] == '*')
       					dp[i][j] = dp[i][j-2];
       				continue;
       			}
       			if(s[i-1] == p[j-1] || p[j-1] == '.')
       				dp[i][j] = dp[i-1][j-1];
       			if(p[j-1] == '*'){
       				if(p[j-2] == s[i-1] || p[j-2] == '.')
       					dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
       				dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i][j];   //转移方程冗余
       			}
       		}
       	}
        // for(auto d:dp){
        //     for(auto p:d){
        //         cout << p << " ";
        //     }
        //     cout << endl;
        // }
       	return dp[s.size()][p.size()];
    }
};