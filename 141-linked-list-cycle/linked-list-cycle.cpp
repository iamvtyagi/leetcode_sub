class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        do{
             slow = slow->next;
             fast = fast->next->next;

             if(slow  == fast) return true;
        }
        while(slow != fast && fast != NULL && fast->next != NULL );

        return false;
    }
};