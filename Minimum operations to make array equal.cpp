class Solution {
public:
    int minOperations(int n) 
    {
        if(n == 1)
        {
            return 0;
        }
        int arr[n];
        int odd = 1;
        for(int i = 0; i < n; i++)
        {
            arr[i] = odd;
            odd += 2;
        }
        int mid;
        if(n % 2 == 0)
        {
            mid = (arr[n / 2] + arr[(n - 1)/ 2]) / 2;
        }
        else
        {
            mid = (arr[n / 2]);
        }
        int ans = 0;
        for(int i = 0; i < n / 2; i++)
        {
            ans += abs(arr[i] - mid);
        }
        return ans;
    }
};
// tc o(N)
// sc o(1)
