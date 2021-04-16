class Solution {
public:
    // without making pair it will not be an efficient solution
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>>st;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                if(s[i] == st.top().first)
                {
                    st.top().second += 1;
                    if(st.top().second == k)
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push({s[i], 1});
                }
            }
        }
        s = "";
        while(!st.empty())
        {
            while(st.top().second--)
            {
                 s += st.top().first;
            }
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// tc o(n)
// sc o(n)
