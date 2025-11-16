class Solution {
public:
    int numSub(string s) {
        int  n = s.size();
        const long long MOD = 1e9+7;
        vector<long long> nums;
        int conti = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1'&& i != n-1) {
                conti++;
            }else if(s[i]=='1'&& i == n-1){
                conti++;
                nums.push_back(conti);
                cout<<conti<<endl;
                conti = 0;
            }
            else{
                if(conti != 0){
                nums.push_back(conti);
                cout<<conti<<endl;
                conti = 0;
                }
            }
        }
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            long long el = nums[i];
           nums[i] =   ((el*(el+1))/2)%MOD;
        }
        for(int i = 0;i<nums.size();i++){
            ans += nums[i];
        }
        return ans;
    }
};