class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         vector<int> ans;
         int n = lists.size();
         for(int i = 0;i<n;i++){

             ListNode* temp = lists[i];
             while(temp != NULL){
                 ans.push_back(temp->val);
                 temp = temp->next;
             }
         }
         sort(ans.begin(),ans.end());
         if(ans.size() == 0 ) return NULL;

         ListNode* root = new ListNode(ans[0]);
         ListNode* temp = root;
         for(int i = 1 ;i<ans.size();i++){
                ListNode* neww = new ListNode(ans[i]);
                temp->next = neww;
                temp = temp->next;
         }
         return root;
    }
};