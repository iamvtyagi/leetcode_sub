class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ii, vector<int>& ni) {
        int n = ii.size();
        int s = ni[0];
        vector<vector<int>> ans;
        bool check = false;
        int e = ni[1];

        if(n==0) return {{s,e}};

        for(int i = 0; i < n; i++) {
            if(!check) {
                if(ii[i][0] < s && ii[i][1] < s) {
                    ans.push_back(ii[i]);
                } 
                else if(ii[i][0] <= s && ii[i][1] >= e) {
                    s = ii[i][0];
                    e = ii[i][1];
                    ans.push_back({s, e});
                    check = true;
                } 
                else if(ii[i][0] <= s) {
                    s = ii[i][0];
                    if(i==n-1){
                        e = e>ii[i][1]?e:ii[i][1];
                        ans.push_back({s,e});
                        check = true;
                    }
                }else if(ii[i][0] > e){
                    ans.push_back({s,e});
                    ans.push_back(ii[i]);
                    check = true;
                }
                else if(ii[i][1] >= e) {
                    e = ii[i][1];
                    ans.push_back({s, e});
                    check = true;
                }
            } 
            else {
                ans.push_back(ii[i]);
            }
        }
        if(!check){
            ans.push_back({s,e});
        }
        return ans;
    }
};