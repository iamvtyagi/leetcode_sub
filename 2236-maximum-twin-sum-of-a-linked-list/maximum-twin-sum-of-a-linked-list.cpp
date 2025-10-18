class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }
        int n = st.size();
        int cnt = 1;
        int res = 0;
        curr = head;
        while(cnt <= n/2){
            res = max(res,curr->val + st.top());
            curr = curr->next;
            st.pop();
            cnt++;
        }
        return res;
    }
};