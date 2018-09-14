class Solution {
public:
    string shortestPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        int step = 0;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
                step++;
            }
            else{
                int tmpright = right + step;
                int tmpstep = 0;
                for(;tmpstep < step;tmpstep++){
                    if(s[tmpright] == s[right]){
                        right--;
                        tmpright--;
                    }
                    else
                        break;
                }
                left -= (step-tmpstep);
                step = tmpstep;
            }
        }
        string ss(s,right+step,s.size()-right+step);
        return ss+s;
    }
};