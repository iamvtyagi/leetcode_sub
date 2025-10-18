class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp = head->next;
        if(temp == NULL) return head;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};