class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        k = k-1;
        while(k){
            p1 = p1->next;
            k--;
        }
        ListNode* temp;
        if(p1->next != NULL){
             temp = p1->next;
        }
        while(temp){
            p2 = p2->next;
            temp = temp->next;
        }
        swap(p1->val,p2->val);
        return head;
    }
};