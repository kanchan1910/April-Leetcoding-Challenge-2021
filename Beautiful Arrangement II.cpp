class Solution {
public:
    vector<int> constructArray(int n, int k) 
    { // intuitive problem
      // observation based
        vector<int>ans(n);
        int l = 1;
        int r = k + 1;
        int i = 0;
        while(l <= r)
        {
            if(i % 2 == 0)
            {
                ans[i]  = l;
                l++;
            }
            else
            {
                ans[i] = r;
                r--;
            }
            i++;
        }
        for(int j = k + 2; j <= n; j++)
        {
            ans[i] = j;
            i++;
        }
        return ans;
    }
};
