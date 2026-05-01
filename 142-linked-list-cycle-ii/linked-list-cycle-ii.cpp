class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        do{
             slow = slow->next;
             fast = fast->next->next;

             if(slow  == fast) break;
        }
        while(slow != fast && fast != NULL && fast->next != NULL );

        ListNode* node = head;

        while(node != slow && slow != NULL && node != NULL ){
            slow = slow->next;
            node = node->next;
        }

        return slow ;        
    }
};