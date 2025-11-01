class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0;i<ans.size();i++){
            if(mp.find(ans[i]) != mp.end()){
                ans[i] = -1;
            }
        }
        int n = ans.size();
        int i = 0;
        ListNode* dummy  = new ListNode(-1);
        temp = dummy;
        while(i<=n-1){
            if(ans[i] != -1){
                temp->next = new ListNode(ans[i]);
                temp = temp->next;
            }
            i++;
        }
        return dummy->next;
    }
};