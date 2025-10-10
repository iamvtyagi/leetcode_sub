class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* evenStart = head->next;

        while(odd && even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;

        }
        odd->next = evenStart;
        return head;
    }
};