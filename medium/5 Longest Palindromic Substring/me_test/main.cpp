class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0;i < s.size();i++){
            for(int j = 0; i-j >= 0 && i+j < s.size(); j++){
                if(s[i-j] != s[i+j])
                    break;
                if(j*2+1 > res.size())
                    res = s.substr(i-j,j*2+1);
            }
            for(int j = 1; i-j >= 0 && i+j-1 < s.size(); j++){
                if(s[i-j] != s[i+j-1])
                    break;
                if(j*2 > res.size())
                    res = s.substr(i-j,j*2);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        int start=0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; i-j >= 0 && i+j < s.size(); j++){
                if(s[i-j] != s[i+j])
                    break;
                if(j*2+1 > len){
                    len = j*2+1;
                    start = i-j;
                }
            }
            for(int j = 1; i-j >= 0 && i+j-1 < s.size(); j++){
                if(s[i-j] != s[i+j-1])
                    break;
                if(j*2 > len){
                    len = j*2;
                    start = i-j;
                }
            }
        }
        return s.substr(start,len);
    }
};