class Solution {
public:
    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){

            ListNode* newnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newnode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow);
        ListNode* first = head;

        while(second != NULL && first != NULL){

            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;

        }

        if(second  ) return false;

        return true;
    }
};