class Solution {
public:
    int dp[105][105][605];
    int fun(vector<string>& strs, int m, int n , int i)
    {
        // base case
        if(m < 0 || n < 0)
        {
            return INT_MIN;
        }
        if(i >= strs.size())
        {
            return 0;
        }
        if(dp[m][n][i] != -1)
        {
            return dp[m][n][i];
        }
        int zero = 0, one = 0;
        for(int j = 0 ; j < strs[i].length();j++)
        {
            if(strs[i][j] == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        int select = fun(strs, m - zero, n - one, i + 1) + 1;
        int reject = fun(strs, m, n, i + 1);
        dp[m][n][i] = max(select, reject);
        return dp[m][n][i];
    }
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        memset(dp, - 1, sizeof(dp));
        return fun(strs, m, n, 0);
    }
};
