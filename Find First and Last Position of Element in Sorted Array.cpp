class Solution {
public:
    // brute force solution
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        bool first_seen = false;
        int first_index = -1, last_index = -1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target && first_seen == false)
            {
                first_index = i;
                first_seen = true;
            }
            if(nums[i] == target)
            {
                last_index = i;
            }
        }
        return {first_index, last_index};
    }
};
// tc o(n)
// sc o(1)


class Solution {
public:
    // so as the given array is sorted, so we can take advantage of this and we can apply binary search here
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first_index = -1, last_index = -1;
        first_index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        last_index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // Because lower_bound returns first element which is equal or GREATER THAN target
        // So, in case the target is not in the list, it will return first greater element than target which will be wrong
        if(first_index == n || nums[first_index] != target)
        {
            return {-1, -1};
        }
        return {first_index, last_index - 1};
    }
};
// tc o(logn)
// sc o(1)


class Solution {
public:
    // so as the given array is sorted, so we can take advantage of this and we can apply binary search here
    int fun1(vector<int>& nums, int target, int n)
    {
        int l = 0; 
        int r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                ans = mid; // can be the answer
                r = mid - 1;
            }
            else if(target < nums[mid])
            {
                r = mid - 1;
            }
            else if(target > nums[mid])
            {
                l = mid + 1;
            }
        }
        return ans;
    }
        int fun2(vector<int>& nums, int target, int n)
    {
        int l = 0; 
        int r = n - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                ans = mid; // can be the answer
                l = mid + 1;
            }
            else if(target < nums[mid])
            {
                r = mid - 1;
            }
            else if(target > nums[mid])
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first_index = -1, last_index = -1;
        first_index = fun1(nums, target, n);
        last_index = fun2(nums, target, n);
        return {first_index, last_index};
    }
};
// tc o(nlogn)
// sc o(1)
