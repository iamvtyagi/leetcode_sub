class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

    auto cmp = [](pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first) return a.second < b.second; 
            return a.first > b.first;
      };
        int n = nums.size();
        unordered_map<int,int> mp;
     priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxh(cmp);

        vector<int> ans;
        for(int i = 0;i<n;i++){
             mp[nums[i]]++;
        }
      for(auto& el : mp){
         maxh.push({el.second,el.first});
      }
      while(!maxh.empty()){
        int a = maxh.top().first;
        for(int i = 0;i<a;i++){
            ans.push_back(maxh.top().second);
        }
        maxh.pop();
      }
      return ans;
    }
};