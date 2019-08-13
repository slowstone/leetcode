class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        int max_k = 0;

        stack<int> num_stack;
        num_stack.push(-1);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                num_stack.push(i);
            }
            else
            {
                num_stack.pop();
                if (num_stack.empty())
                {
                    num_stack.push(i);
                }
                else
                {
                    max_k = max(max_k, i - num_stack.top());
                }
            }
        }

        return max_k;
    }
};

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int m = s.length();
        int res = 0;
        vector<int> dp(m + 1, 0);
        for (int i = m - 1; i >= 0; --i)
        {
            if (s[i] == ')')
            {
                continue;
            }
            if (i + 1 + dp[i + 1] < m && s[i + 1 + dp[i + 1]] == ')')
            {
                dp[i] = 2 + dp[i + 1];
                if (i + dp[i] <= m)
                {
                    dp[i] += dp[i + dp[i]];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};