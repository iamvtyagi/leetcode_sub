class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for(int i = 0;i<n;i++){
            if(bits[i]==0){
                continue;
            }
            if(bits[i]==1 && i+1<n){
                if(bits[i+1]==0 || bits[i+1]==1){
                    if(i+1==n-1) return false;
                    i++;
                }
            }
        }
        return true;
    }
};