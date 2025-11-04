class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<n-k+1;i++){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            unordered_map<int,int> mp;
            for (int j = i; j < i + k && j < n; j++) {
                mp[nums[j]]++;
            }
            for(auto& el : mp){
                if(pq.size()<x){
                    pq.push({el.second,el.first});
                }else{
                    pq.push({el.second,el.first});
                    pq.pop();
                }
            }
            int sum = 0;
            while(!pq.empty()){
                sum += pq.top().second * pq.top().first;
                pq.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};