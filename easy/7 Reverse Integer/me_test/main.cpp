class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x == INT_MIN || x == INT_MAX) return 0;
        int sign = 1;
        if(x < 0){ 
            sign = -1;
            x = -x;
        }
        int res = 0;
        while(x!=0){
            int cur = x%10;
            if(res > INT_MAX / 10 || (res == INT_MAX/10 && cur > 7))
                return 0;
            res = res * 10 + cur;
            x = x / 10;
        }
        return res * sign;
    }
};

class Solution {
public:
    int reverse(int x) {
        long out = 0;
        while(x != 0)
        {
            out = out *10 + x%10;
            x/=10;
        }
        
        return (out < -2147483648|| out >= 2147483648)?0:out;
    }
};