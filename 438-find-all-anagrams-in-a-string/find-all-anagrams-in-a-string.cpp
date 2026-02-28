class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        vector<int> ans;
        if(m<n){
            return ans;
        }
        unordered_map<char , int> mp;
        for(int i = 0;i<n;i++){
            mp[s1[i]]++;
        }
        int cnt = mp.size();
        int i = 0;
        int j = 0;
        while(j<m){
            mp[s2[j]]--;
            if(mp[s2[j]]==0){
                mp.erase(s2[j]);
                cnt--;
            }
            if(j-i+1<n){
                j++;
            }else if(j-i+1==n){
                if(mp.size()==0 && cnt==0){
                    ans.push_back(i);
                }
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1) cnt++;
                    if(mp[s2[i]]==0) mp.erase(s2[i]);
                    i++;
                    j++;
            }
        }
        return ans; 
    }
};