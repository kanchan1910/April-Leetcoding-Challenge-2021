
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int len  = 0;
        ListNode* cur = head;
        // finding length of the linked list
        while(cur != NULL)
        {
            len++;
            cur = cur->next;
        }
        // nth node from the beginning
        int val = len - n + 1;
        int count = 0;
        ListNode* prev = NULL;
        cur = head;
        while(cur != NULL)
        {
            count++;
            ListNode* next = cur->next;
            if(count == val)
            {
                if(prev != NULL)
                {
                    prev->next = next;
                    break;   
                }
                else
                {
                // case when we have to remove the head node of the linked list
                    return next;
                }
            }
            prev = cur;
            cur = next;
        }
        return head;
    }
};
// tc o(n) + o(n) ~ o(n)
// sc o(1)



// single pass solution----- single pass means that each node is visited only once
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        n--;
        while(n--)
        {
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // slow node will be out target nth node from the last
        if(prev == NULL)
        {
            return slow->next;
        }
        else
        {
            prev->next = slow->next;
        }
        return head;
    }
};
// fast pointer moves o(n) as it visits each node once
// slow pointer moves o(nthnode) 
// tc o(n)
// sc o(1)
