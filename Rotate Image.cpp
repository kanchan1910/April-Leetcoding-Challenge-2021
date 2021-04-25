class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(n == 0)
        {
            return;
        }
        int m = matrix[0].size();
        // transpose
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // rotate
        for(int i = 0; i < n; i++)
        {
         for(int j = 0; j < m / 2; j++)
        {
            swap(matrix[i][j], matrix[i][m - j - 1]);
        }   
        }
        return;
    }
};

// ct o(n*m)
// sc o(1)
