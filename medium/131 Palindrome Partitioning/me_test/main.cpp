class Solution {
private:
	
public:
    vector<vector<string>> partition(string s) {
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
    }
};