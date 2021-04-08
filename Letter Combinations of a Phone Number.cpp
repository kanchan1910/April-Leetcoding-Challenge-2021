class Solution {
public:
map<int, string>m = 
{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
};
    void fun(string digits, vector<string>&ans, int index, string op)
    {
        if(index == digits.length())
        {
            ans.push_back(op);
            return;
        }
        for(int k = 0; k < m[digits[index] - '0'].length(); k++)
        {
            op += m[digits[index] - '0'][k];
            fun(digits, ans, index + 1, op);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string>ans;
        int n = digits.length();
        if(n == 0)
        {
            return ans;
        }
        fun(digits, ans, 0, "");
        return ans;
    }
};
