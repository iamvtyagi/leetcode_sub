class Solution {
public:
    bool canPlace(vector<int>& pos, int m, int dist) {
        int count = 1; // first ball placed
        int last = pos[0];

        for(int i = 1; i < pos.size(); i++) {
            if(pos[i] - last >= dist) {
                count++;
                last = pos[i];
            }
        }

        return count >= m;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());

        int low = 1;
        int high = pos.back() - pos.front();
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(canPlace(pos, m, mid)) {
                ans = mid;      
                low = mid + 1;  
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};