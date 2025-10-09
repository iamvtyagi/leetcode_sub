class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        if(slow == NULL || slow->next == NULL ) return NULL;
        while(fast != NULL && fast->next != NULL ){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
         return head;
    }
};