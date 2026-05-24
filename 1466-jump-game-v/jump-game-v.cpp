class Solution {
public:
    int n;
    
    vector<int>dp;
    int find(vector<int>& arr, int d,int i){
        if(dp[i]!=-1) return dp[i];

        int maxi=0;

        for(int k=1;k<=d;k++){
            int j=i-k;
            if(j>=0&&j<n&&arr[i]<=arr[j]) break;
            if(j>=0&&j<n&&arr[i]>arr[j]){
                maxi=max(maxi,find(arr,d,j));
            }
            
        }
        for(int k=1;k<=d;k++){
            int j=i+k;
            if(j>=0&&j<n&&arr[i]<=arr[j]) break;
            if(j>=0&&j<n&&arr[i]>arr[j]){
                maxi=max(maxi,find(arr,d,j));
            }
            
        }
        return dp[i]=1+maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.assign(n,-1);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,find(arr,d,i));
        }
        return maxi;

    }   
};