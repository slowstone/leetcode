class Solution {
public:
    string shortestPalindrome(string s) {
        int len = 0;
        for(int i = 0;i < s.size();i++){
            int left = i,right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(left == 0)
                    len = max(right-left+1,len);
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(left == 0)
                    len = max(right-left+1,len);
                left--;
                right++;
            }
        }
        string res = s;
        for(int i = len;i < s.size();i++){
            res = s[i] + res;
        }
        // cout << len << endl;
        return res;
    }
};