class Solution {
public:
    int dp[101][101];
    int fun(vector<vector<int>>& obstacleGrid, int n, int m, int i, int j)
    {
        if(i >= n || j >= m || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if(i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = fun(obstacleGrid, n, m, i + 1, j) + fun(obstacleGrid, n, m, i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
        {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return fun(obstacleGrid, n, m, 0, 0);
    }
};
// tc o(n*m)
// sc o(n*m)
