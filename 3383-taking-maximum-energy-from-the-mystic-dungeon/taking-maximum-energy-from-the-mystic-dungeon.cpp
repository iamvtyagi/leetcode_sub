class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int cnt = 0;
        for(int i = n-1;i>=0;i--){
             if(cnt<k){
                cnt++;
                 continue;
             }else{
                energy[i] += energy[i+k];
             }
        }
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            maxi = max(energy[i],maxi);
        }
        return maxi;
    }
};