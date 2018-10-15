class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int ssize = s.size();
        if (ssize == 0) {
            return 0;
        }
        vector<int> solution(ssize, 1);
        for (int end = 1; end < ssize; end++) {
            int max_len = 0;
            for (int start = end-1; start >=0; start--) {
                int prev_max = max_len;
                
                if (solution[start] > max_len) {
                    max_len = solution[start];
                }
                if (s[start] == s[end]) {
                    solution[start] = prev_max + 2;    
                }
            }
        }
        int result = 0;
        for (int sol : solution) {
            result = max(result, sol);
        }
        return result;
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        if (sz < 2)
            return sz;
        vector<int> dp(sz, 1);
        
        for (int i = 1; i < sz; i++) {
            int pre_j = 0;
            for (int j = i - 1; j >= 0; j--) {
                int tmp = dp[j];
                
                if (s[i] == s[j])
                    dp[j] = pre_j + 2;
                else
                    dp[j] = max(dp[j], dp[j + 1]);
                pre_j = tmp;
            }
        }
        
        return dp[0];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty() || s.size() == 0) {
            return 0;
        }
        int size = s.size();
        vector<int> dp(size, 1);
        for(int i = 1; i < size; ++i) {
            int cur = 0;
            for(int j = i-1; j >= 0; --j) {
                int temp = dp[j];
                if(s[i] == s[j]) {
                    dp[j] = cur + 2;
                }
                cur = max(cur, temp);
            }
        }
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;        
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            int len = 0;
            for (int j = i + 1; j < n; ++j) {
                int t = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = len + 2;
                }
                len = max(len, t);
            }
        }
        for (int num : dp) res = max(res, num);
        return res;    
    }
};