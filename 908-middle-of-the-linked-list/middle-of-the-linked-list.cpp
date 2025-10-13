class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int cntToMid = cnt/2;
        temp = head;
        while(cntToMid){ 
             temp = temp->next;
             cntToMid--;
        }
        return temp;
    }
};