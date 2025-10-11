class Solution {
public:
 vector<int> prevSmall(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmall(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> nsl = prevSmall(arr);
        vector<int> nsr = nextSmall(arr);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;        
    }
};