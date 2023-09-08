class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        
        int len = 1;
        ListNode *t = head;

        while(t->next){
            ++len;
            t = t->next;
        }
        t->next = head;
        k = k % len;
        k = len - k;
        while(k--){
            t = t->next;
        }
        head = t->next;
        t->next = NULL;
        return head;
    }
};