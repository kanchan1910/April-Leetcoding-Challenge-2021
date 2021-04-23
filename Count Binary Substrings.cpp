class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int ans = 0;
        int zero = 0, one = 0;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                zero = 0;
                while(s[i] == '0')
                {
                    i++;
                    zero++;
                }
                i--;
                ans += min(one, zero);
            }
            else if(s[i] == '1')
            {
                one = 0;
                while(s[i] == '1')
                {
                    i++;
                    one++;
                }
                i--;
                ans += min(one, zero);
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
