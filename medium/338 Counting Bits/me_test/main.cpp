class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        int tmp = 1;
        for(int i = 1;i <= num;i++){
            if(i%2 != 0)
                dp[i] = dp[i-1]+1;
            else{
                if(i == tmp*2){
                    dp[i] = 1;
                    tmp = (tmp << 1);
                }
                else
                    dp[i] = dp[i-tmp]+1;
            }
        }
        return dp;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++)
            res.push_back(helper(i));
        
        return res;
    }
    //count the 1's in the binary representation of a num
    int helper(int num){
        int cnt = 0;
        while(num){
            if(num & 0x1)
                cnt++;
            num = num >> 1;
        }
        return cnt;
    }
};