class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int> helper;
        if(head == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int cnt = 1;
        while(temp && temp->next){
             if(cnt % 2 != 0){
                helper.push_back(temp->next->val);
                 temp->next = temp->next->next;
                 temp = temp->next;
             }
             cnt++;
        }

        temp = head;
        while(temp->next != NULL){
             temp = temp->next;
        }
        int n = helper.size();
        for(int i = 0;i<n;i++){
            ListNode* neww = new ListNode(helper[i]);
            temp->next = neww;
            temp = temp->next;
        }
        return head;
    }
};