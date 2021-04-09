class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        /*
        // if it was a normal problem of just checking that the string of vector is in lexicographical order or not
        int n = words.size();
        for(int i = 0; i < n - 1; i++)
        {
            string str1 = words[i];
            string str2 = words[i + 1];
            if(str1 > str2)
            {
                return false;
            }
        }
        return true;*/
        
        // but for this problem we have given the alien dictionary accoprding to which we have to check if the words in the string vector are in lexicographical order or not
        // so we can't directly do str1 < str2
        int n = words.size();
        vector<int>m(26, 0);
        for(int i = 0; i < order.length(); i++)
        {
            m[order[i] - 'a'] = i;
        }
        for(int i = 0; i < n - 1; i++)
        {
            bool flag = false;
            string str1 = words[i];
            string str2 = words[i + 1];
            for(int j = 0; j < min(str1.length(), str2.length()); j++)
            {
                if(m[str1[j] - 'a'] > m[str2[j] - 'a'])
                {
                   return false;
                }
                else if(m[str1[j] - 'a'] < m[str2[j] - 'a'])
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false && str1.length() > str2.length())
            {
                return false;
            }
        }
        return true;
    }
};
