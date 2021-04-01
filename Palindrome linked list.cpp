class Solution {
public:
    bool fun(string str)
    {
        int n = str.length();
        for(int i = 0 ; i < n / 2; i++)
        {
            if(str[i] != str[n - i -1])
            {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head)
    {
        string ans = "";
        ListNode* cur = head;
        while(cur != NULL)
        {
            ans += to_string(cur->val);
            cur = cur->next;
        }
        return fun(ans);
    }
};
// tc o(n)
// sc o(1)

// Other great solution


class Solution {
public:
    // finding reverse of the linked list
    ListNode* reverse(ListNode* root)
    {
        ListNode* prev = NULL;
        while(root != NULL)
        {
            ListNode* next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        // finding middle of the linked list;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* firsthalf = head;
        ListNode* secondhalf = slow->next;
        secondhalf = reverse(secondhalf);
        // comparing the two halfs of the linked list
        while(secondhalf != NULL)
        {
            if(firsthalf->val != secondhalf->val)
            {
                return false;
            }
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }
        return true;
    }
};
// tc o(n)
// sc o(1)
