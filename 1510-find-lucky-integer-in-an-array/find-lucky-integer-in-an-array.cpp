class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi =  INT_MIN;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto& el : mp){
            if(el.first == el.second){
                maxi = max(el.first,maxi);
            }
        }
        return (maxi!=INT_MIN)?maxi:-1;
    }
};