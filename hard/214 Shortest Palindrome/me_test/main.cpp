class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0;
        int j = 0;
        int k = 0;
        string stmp;
        while(i < j){
            if(s[i] != s[j]){
                if(i == 0){
                    stmp = stmp+s[j];
                    j--;
                }
                else
                    i = 0;
                k = j+1;
            }
            else{
                i++;
                stmp = stmp+s[j];
                j--;
            }
        }
        return ss+s;
    }
};