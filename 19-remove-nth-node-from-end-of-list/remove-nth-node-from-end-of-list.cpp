class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;

        // 1. Total nodes count karo
        while(temp){
            cnt++;
            temp = temp->next;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        int target = cnt - n; // Kis position tak jaana hai

        // 2. Agar target 0 hai, matlab head node hi remove karna hai
        if (target == 0) {
            ListNode* newHead = head->next;
            // delete head; 
            return newHead;
        }

        // 3. Target node tak pahuncho
        while(target > 0){
            prev = curr;
            curr = curr->next;
            target--;
        }

        // 4. Node ko skip karo
        if(prev && curr) {
            prev->next = curr->next;
        }

        return head;
    }
};