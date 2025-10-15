class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         vector<int> nums;
         ListNode* temp = list1;
         while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
         }
          temp = list2;
         while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
         }
         sort(nums.begin(),nums.end());
         ListNode* dummy = new ListNode(-1);
         temp = dummy;
         for(int i = 0;i<nums.size();i++){
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
         }
         return dummy->next;
    }
};