class Solution {
public:
    int dp[205][205];
    int dfs(vector<vector<int>>&matrix, int n, int m, int i, int j, int parent)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || parent >= matrix[i][j])
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int l = dfs(matrix, n, m, i, j - 1, matrix[i][j]);
        int r = dfs(matrix, n, m, i, j + 1, matrix[i][j]);
        int u = dfs(matrix, n, m, i - 1, j, matrix[i][j]);
        int d = dfs(matrix, n, m, i + 1, j, matrix[i][j]);
        dp[i][j] = max({l, r, u, d}) + 1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
               ans = max(ans, dfs(matrix, n, m, i, j, -1));
            }
        }
        return ans;
    }
};
