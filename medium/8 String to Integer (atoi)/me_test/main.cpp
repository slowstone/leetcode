class Solution {
public:
    int myAtoi(string str) {
        int sum = 0;
        int start = 0;
        int sigh = 1;
        for(;start < str.size();start++){
            if(str[start] != ' ')
                break;
        }
        if(str.size() <= start) return sum;
        if(str[start] == '-') {
            sigh = -1;
            start++;
        }
        else if(str[start] == '+'){
            sigh = 1;
            start++;
        }
        while(start < str.size()){
            if(str[start] < '0' || str[start] > '9') break;
            if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && str[start] > '7'))
                return sigh == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + (str[start] - '0');
            start++;
        }
        return sum * sigh;
    }
};