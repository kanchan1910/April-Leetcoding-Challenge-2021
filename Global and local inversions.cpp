class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
      // approach 1 
        int n = A.size();
        int local = 0, global = 0;
        if(n <= 2)
        {
            return true;
        }
        for(int i = 0 ; i < n - 1; i++)
        {
            if(A[i] > A[i + 1])
            {
                local++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n ;j++)
            {
                if(A[i] > A[j])
                {
                    global++;
                }
            }
        }
        return local == global;
    }
};
// TLE
// tc o(N) + O(N * N) = O(N * N)
// sc o(1)


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
      // approach 2
        int n = A.size();
        int local = 0, global = 0;
        if(n <= 2)
        {
            return true;
        }
        // as we know global can only be >= local
        // so global count is atleast local count
        // we just need to check if we have global count other than the local count
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 2; j < n ;j++)
            {
                if(A[i] > A[j])
                {
                   return false;
                }
            }
        }
        return true;
    }
};
// TLE
// tle O(N * N)
// sc o(1)


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
      // approach 3
        int n = A.size();
        int local = 0, global = 0;
        if(n <= 2)
        {
            return true;
        }
        int mx_till_now = A[0];
        for(int i = 0; i <= n - 3; i++)
        {
            mx_till_now = max(mx_till_now, A[i]);
            if(mx_till_now > A[i + 2])
            {
                return false;
            }
        }
        return true;
    }
};
// ACCEPTED
// tc o(N)
// sc O(1)


class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
      // approach 4
        int n = A.size();
        int local = 0, global = 0;
        if(n <= 2)
        {
            return true;
        }
        // we can take benefit of the fact that the given array is the permutation
        for(int i = 0 ; i < n; i++)
        {
            if(A[i] != i && A[i] != i - 1 && A[i] != i + 1)
            {
                return false;
            }
        }
        return true;
    }
};

// ACCEPTED
// tc o(N)
// sc O(1)
