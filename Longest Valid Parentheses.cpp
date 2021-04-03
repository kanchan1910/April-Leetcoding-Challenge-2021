class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        stack<int>index;
        int ans = 0;
        if(n == 0)
        {
            return 0;
        }
        index.push(-1);
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')
            {
                index.push(i);
            }
            else
            {
                if(!index.empty())
                {
                    index.pop();
                }
                if(!index.empty())
                {
                    ans = max(ans, i - index.top());
                }
                else
                {
                    index.push(i);
                }
            }
        }
        return ans;
    }
};

// tc o(n)
// sc o(n)


class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int ans = 0;
        int l = 0, r = 0;
        if(n == 0)
        {
            return 0;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if(l == r)
            {
                ans = max(ans, 2 * l);
            }
            if(r > l)
            {
                l = 0, r = 0;
            }
        }
        l = 0, r = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if(l == r)
            {
                ans = max(ans, 2 * l);
            }
            if(l > r)
            {
                l = 0, r = 0;
            }
        }
        return ans;
    }
};

// tc o(n)
// sc o(1)
