class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-1;i++){
            if(nums[i]==0) continue;
            for(int j = i+1;j<n;j++){
                 int l = j+1;
                 int r = n-1;
                 int x = nums[i]+nums[j];
                 int ans=-1;
                 while(l<=r){
                     int mid = l + (r-l)/2;
                     if(nums[mid] < x){
                          ans = mid;
                          l = mid+1;
                     }else{
                        r = mid-1;
                     }
                 }
                 if(ans!=-1){
                     cnt += ans-j;
                 }
            }
        }
        return cnt;
    }
};