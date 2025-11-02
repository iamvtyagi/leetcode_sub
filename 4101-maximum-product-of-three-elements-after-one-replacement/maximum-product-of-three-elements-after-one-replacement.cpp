class Solution {
public:
    long long maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    unordered_map<int,int> mp;
    for(auto& el : nums){
        mp[abs(el)]++;
    }
        int n  = nums.size();
        // find three sbse bade no
        int phela = INT_MIN;
        int doosra = INT_MIN;
        int teesra = INT_MIN;
        for(int i = 0;i<n;i++){
            if(abs(nums[i]) > phela){
                teesra = doosra;
                doosra = phela;
                phela = abs(nums[i]);
            }
        }
        if(mp[phela]>=3){
            teesra = phela;
            doosra = phela ;
        }else if(mp[phela]==2){
            teesra = doosra;
            doosra = phela;
        }else if(mp[doosra]>=2){
            teesra = doosra;
        }
        cout<<phela<<" "<<doosra<<" "<<teesra;
   // step 2 : find smallest in these threee already done 
   // strep 3: convert smallest to 10^5
      teesra = 1e5;
      long long ans = 1LL * phela * doosra * teesra;
      return ans;
    }
};