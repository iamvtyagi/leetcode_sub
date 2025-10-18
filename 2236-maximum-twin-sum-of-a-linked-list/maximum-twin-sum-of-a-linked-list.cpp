class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        int j = nums.size()-1;
        int maxSum = 0;
        while(i<j){
            maxSum = max(maxSum,nums[j]+nums[i]);
            i++;
            j--;
        }
        return maxSum;
    }
};