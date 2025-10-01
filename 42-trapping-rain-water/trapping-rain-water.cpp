class Solution {
public:
   void printvec(vector<int> &veci){
        for(int i = 0;i<veci.size();i++){
              cout<<veci[i]<<" ";
        }
        cout<<endl;
   }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax;
        vector<int> rightMax;
        int lefti = height[0];
        int righti = height[n-1];
        //  leftMax.push_back(lefti);
        //  rightMax.push_back(righti);
        for(int i = 0;i<n;i++){
             lefti = max(lefti , height[i]);
             leftMax.push_back(lefti);
             righti = max(righti , height[n-i-1]);
             rightMax.push_back(righti);
        }
        reverse(rightMax.begin(),rightMax.end());
        printvec(leftMax);
        printvec(rightMax);
        vector<int> mini;
        for(int i = 0;i<n;i++){
            int val = min(leftMax[i],rightMax[i]);
            mini.push_back(val);
        }
        printvec(mini);
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += mini[i] - height[i];
        }
        return ans;
    }
};