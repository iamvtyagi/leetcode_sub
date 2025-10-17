class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int,ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        mp[0] = dummy;
        dummy->next = head;
        while(head != NULL){
             prefixSum += head->val;
             if(mp.find(prefixSum) != mp.end()){
                // here goes the deletion work hehe
                ListNode* start = mp[prefixSum];
                ListNode* temp = start->next;
                int pSum = prefixSum;
                while(temp != head){
                     pSum += temp->val;
                     mp.erase(pSum);
                     temp = temp->next;
                }
                start->next = head->next;
             }else{
                mp[prefixSum] = head;
             }
             head = head->next;
        }
        return dummy->next;
    }
};