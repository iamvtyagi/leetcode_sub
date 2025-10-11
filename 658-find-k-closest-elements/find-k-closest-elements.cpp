class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>> maxh;
        for(int i = 0;i<n;i++){
            if(maxh.size() < k){ 
                maxh.push({abs(arr[i]-x),arr[i]});
            }else{
                maxh.push({abs(arr[i]-x),arr[i]});
                maxh.pop();
            }
        }
        vector<int> ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};