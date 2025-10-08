class Solution {
public:
    int bSearch(int i , int j , int spell ,long long success , vector<int>& potions){
         int l = i;
         int r = j;
         int ans = -1;
         while(l <= r){ 
            int mid = l + (r-l)/2;
            if(1LL * spell * potions[mid] >= success){
                  ans = mid;
                  r = mid -1 ;
            }else{
                l = mid + 1;
            }
         }
         return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i = 0;i<n;i++){
             int idx = bSearch(0,m-1,spells[i],success , potions);
            if(idx != -1){
             ans.push_back(m-idx);
            }else{
                 ans.push_back(0);
            }
        }
        return ans;
    }
};