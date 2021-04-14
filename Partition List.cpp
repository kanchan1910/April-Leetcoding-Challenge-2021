class Solution 
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        ListNode* cur1 = NULL;
        ListNode* cur2 = NULL;
        ListNode* cur = head;
        ListNode* tmp = NULL;
        
        while(cur != NULL)
        {
            tmp = cur->next;
            if(cur->val < x)
            {
                if(head1 == NULL)
                {
                    head1 = cur;
                    cur1 = cur;
                }
                else
                {
                    cur1->next = cur;
                    cur1 = cur;
                    cur1->next = NULL;
                }
            }
            else
            {
                 if(head2 == NULL)
                {
                    head2 = cur;
                    cur2 = cur;
                    head2->next = NULL;
                }
                else
                {
                    cur2->next = cur;
                    cur2 = cur;
                    cur2->next = NULL;
                }
            }
            cur = tmp;
        }
        
        if(head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        if(head1 == NULL)
        {
            return head2;
        }
        if(head2 == NULL)
        {
            return head1;
        }
        
        cur1->next = head2;
        return head1;
    }
};

// tc o(n)
// sc o(1)
