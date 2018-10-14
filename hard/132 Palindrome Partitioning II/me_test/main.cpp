class Solution {
private:
	bool isPalindrome(string s,int left,int right){
		while(left < right){
			if(s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= s.size();i++){
        	for(int j = 0;j < i;j++){
        		if(isPalindrome(s,j,i-1))
        			dp[i] = min(dp[j] + 1,dp[i]);
        	}
        }
        return dp[s.size()]-1;
    }
};

class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,INT_MAX);
        vector<vector<bool>> ispalindrome(s.size(),vector<bool>(s.size(),false));
        for(int i = 0;i < s.size();i++){
            int left = i,right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                ispalindrome[left][right] = true;
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                ispalindrome[left][right] = true;
                left--;
                right++;
            }
        }
        dp[0] = 0;
        for(int i = 1;i <= s.size();i++){
            for(int j = 0;j < i;j++){
                if(ispalindrome[j][i-1])
                    dp[i] = min(dp[j] + 1,dp[i]);
            }
        }
        return dp[s.size()]-1;
    }
};