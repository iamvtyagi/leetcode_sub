class Solution {
public:
    int findlength(ListNode* head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int l = findlength(head);
        if(k>l){
            return head;
        }
        cout<<l<<endl;
        int forKth = k-1;
        cout<<forKth<<endl;
        ListNode* k1 = head;
        while( forKth){
            k1 = k1->next;
            forKth--;
        }
        ListNode* k2 = head;
        int forEndKth = l - k;
        cout<<forEndKth<<endl;
        while(forEndKth){
            k2 = k2->next;
            forEndKth--;
        }
        if(k1 && k2 ){
            swap(k1->val , k2->val);
        }
        return head;
    }
};