class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;


        ListNode* temp = head;
        int cnt =  0;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        k = k % cnt;
        if(k == 0) return head; 


        int target = cnt - k;
        temp = head;

        while(--target){
            temp = temp->next;
        }

        ListNode* ptr;

        if(temp->next){
            ptr = temp->next;
        }
        temp->next = NULL;

        temp = ptr;

        while(ptr && ptr->next){
            ptr = ptr->next;
        }

        ptr->next = head;

        return temp;

    }
};