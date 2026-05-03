class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy; 

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            
            int val = sum % 10;
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;

            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;
        }

        while(l1){
            int sum = l1->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;

            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;
        }

        while(l2){
            int sum =  l2->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            l2 = l2->next;

            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;
        }

        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return dummy->next;
    }
};