// prerequisit subarray sum equal k problem 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        if(n == 0)
        {
            return 0;
        }
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m ; j++)
            {
                matrix[i][j] += matrix[i][j - 1]; 
            }
        }
        int ans = 0;
        for(int startcol = 0; startcol < m ; startcol++)
        {
            for(int curcol = startcol; curcol < m; curcol++)
            {
                unordered_map<int, int>m;
                int sum = 0;
                m[0]++;
                for(int row = 0; row < n; row++)
                {
                    sum += matrix[row][curcol];
                    if(startcol > 0)
                    {
                        sum -= matrix[row][startcol -1];
                    }
                    if(m.find(sum - target) != m.end())
                    {
                        ans += m[sum - target];
                    }
                    m[sum]++;
                }
                
            }
        }
        return ans;
    }
};
// tc o(n * m * m)
// sc o(n)
