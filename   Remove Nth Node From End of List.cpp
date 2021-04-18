
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
