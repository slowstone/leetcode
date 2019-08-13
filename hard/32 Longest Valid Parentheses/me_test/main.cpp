class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> sti;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(')
            {
                sti.push(0);
            }
            else if (c == ')')
            {
                int cur = 0;
                while (!sti.empty() && sti.top() != 0)
                {
                    cur += sti.top();
                    sti.pop();
                }
                if (!sti.empty() && sti.top() == 0)
                {
                    cur += 2;
                    sti.pop();
                    while (!sti.empty() && sti.top() != 0)
                    {
                        cur += sti.top();
                        sti.pop();
                    }
                    sti.push(cur);
                }
                res = max(res, cur);
            }
            else
            {
                while (!sti.empty())
                {
                    sti.pop();
                }
            }
        }
        return res;
    }
};