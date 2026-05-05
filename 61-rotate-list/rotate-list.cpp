class Solution {
public:
    ListNode* reverse(ListNode* start , ListNode* end){

        ListNode* curr = start;
        ListNode* prev = NULL;

        while(curr != end){
            ListNode* node = curr->next;

            curr->next = prev;
            prev = curr;
            curr = node;

        }

        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;

        
        ListNode* temp = head;
        int cnt =  0;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        k = k % cnt;

        int target = cnt - k;
        temp = head;

        while(target && temp){
            target--;
            temp = temp->next;
        }

       ListNode* part1 =  reverse(head,temp); // temp is one step behind jha tak reverse krna hai 
       ListNode* part2 =  reverse(temp,NULL);

       temp = part1;
       while(temp->next){
        temp = temp->next;
       }

       temp->next = part2;

      ListNode* ans =  reverse(part1,NULL);

       return ans;
    }
};