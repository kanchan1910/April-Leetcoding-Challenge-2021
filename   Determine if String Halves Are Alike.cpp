class Solution {
public:
    int fun(string str)
    {
        int count = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                count++;
            }
        }
        return count;
    }
    bool halvesAreAlike(string s) 
    {
        int n = s.length();
        return (fun(s.substr(0, n / 2)) == fun(s.substr(n / 2, n/ 2)) == true);
    }
};
