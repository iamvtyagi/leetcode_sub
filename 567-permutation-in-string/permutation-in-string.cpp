class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m<n){
            return false;
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
                    return true;
                }else{
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1) cnt++;
                    if(mp[s2[i]]==0) mp.erase(s2[i]);
                    i++;
                    j++;
                }
            }
        }
        return false; 
    }
};