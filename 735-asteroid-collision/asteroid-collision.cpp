class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int val = ast[i];
            bool alive = true;

            // Collision only happens if top is moving RIGHT (+) and current is moving LEFT (-)
            while (!st.empty() && st.top() > 0 && val < 0 && alive) {
                if (st.top() < abs(val)) {
                    // Top asteroid is smaller, it explodes. Keep checking the next ones.
                    st.pop();
                    continue; 
                } else if (st.top() == abs(val)) {
                    // Both are equal size, both explode.
                    st.pop();
                    alive = false; 
                    break;
                } else {
                    // Top asteroid is bigger, current one explodes.
                    alive = false;
                    break;
                }
            }

            // Only push if the current asteroid survived all collisions
            if (alive) {
                st.push(val);
            }
        }

        // Convert the stack back into a vector
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};