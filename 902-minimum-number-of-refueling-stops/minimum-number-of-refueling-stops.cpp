class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int limit = startFuel;
        int cnt = 0;
        int i = 0; 

        while(limit<target){
             while(i<stations.size() && stations[i][0] <= limit){
                    pq.push(stations[i][1]);
                    i++;
             }
             if(pq.empty()) return -1;
             cnt++;
             limit += pq.top();
             pq.pop();
        }
        return cnt;
    }
};