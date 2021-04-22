class Solution {
public:
    // gap + cross = number of rows
    // no of rows = constant
    // cross = no of rows - gap
    // cross min = gap more
    // task is to find the positions where there are maximum number of gaps
    int leastBricks(vector<vector<int>>& wall) 
    {
        int n = wall.size();
        int maxi = 0;
        unordered_map<int, int>m;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < wall[i].size() -1; j++)
            {
                sum += wall[i][j];
                m[sum]++;
                maxi = max(maxi, m[sum]);
            }
        }
        return n - maxi;
    }
};
// tc o(n*n)
// sc o(1)
