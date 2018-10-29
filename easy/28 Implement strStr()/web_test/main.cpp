class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h=haystack.size();
        int n=needle.size();
        if(n==0){return 0;}
        for(int i=0;i<h-n+1;i++){
            bool all_match=true;
            for(int j=0;j<n && all_match;j++){
                all_match=all_match&&(haystack[i+j]==needle[j]);
            }
            if(all_match){
                return i;
            }
        }    
            return -1;
        
        
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        size_t i = 0;
        size_t j = 0;
        
        while (i < hLen && j < nLen) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                i -= j - 1;
                j = 0;
            }
        }
        
        return (i <= hLen && j == nLen) ? i - j : -1;
    }
};