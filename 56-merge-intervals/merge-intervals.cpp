class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int sp = intervals[0][0];
        int ep = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(intervals[i][0] <= ep && intervals[i][1] >= ep){
                  ep = intervals[i][1];
            }
            else if(intervals[i][0] <= ep && intervals[i][1] <= ep){
                    continue;
            }
            else{
                  ans.push_back({sp,ep});
                  sp = intervals[i][0];
                  ep = intervals[i][1];
            }
        }
        ans.push_back({sp,ep});
        return ans;
    }
};