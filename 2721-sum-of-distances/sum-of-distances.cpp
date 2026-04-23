class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long> suff,pref;
        unordered_map<int,int> last,cnt1,cnt2;
        vector<long long> ans;
        int n=nums.size();

        for(int i=n-1;i>=0;i--){
            if(last.find(nums[i])!=last.end()){
                int dis=last[nums[i]]-i;
                suff[nums[i]]+=(cnt1[nums[i]]*dis);
                cnt1[nums[i]]++;
                last[nums[i]]=i;
            }else{
                last[nums[i]]=i;
                cnt1[nums[i]]=1;
                suff[nums[i]]=0;
            }
        } 
        last.clear();

        for(int i=0;i<n;i++){

            if(last.find(nums[i])!=last.end()){
                suff[nums[i]]-=(cnt1[nums[i]]*(i-last[nums[i]]));
                pref[nums[i]]+=(i-last[nums[i]])*cnt2[nums[i]];
            }

            long long val=max(0LL,pref[nums[i]]+suff[nums[i]]);
            ans.push_back(val);

            last[nums[i]]=i;
            cnt2[nums[i]]++;
            cnt1[nums[i]]--;

        }

        return ans;
        
    }
};