class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax;
        vector<int> suffixMax;
        vector<int> mini;
        int ans = 0;
        int n = height.size();
        prefixMax.push_back(-1);
        int leftMeiBada = height[0];
        for(int i = 1;i<n;i++){
            prefixMax.push_back(leftMeiBada);
            leftMeiBada = max(leftMeiBada,height[i]);
        }
        suffixMax.push_back(-1);
        int rightMeiBada = height[n-1];
        for(int i = n-2;i>=0;i--){
            suffixMax.push_back(rightMeiBada);
            rightMeiBada = max(rightMeiBada,height[i]);
        }
        reverse(suffixMax.begin(),suffixMax.end());
        // cout<<prefixMax.size()<<endl;
        // cout<<suffixMax.size()<<endl;

        for(int i = 0;i<prefixMax.size();i++){
             int minii = min(prefixMax[i],suffixMax[i]);
             mini.push_back(minii);
        }

        //  for(int i = 0;i<prefixMax.size();i++){
        //     cout<<prefixMax[i]<<" ";
        //   }
        //    cout<<endl;

        
        //  for(int i = 0;i<prefixMax.size();i++){
        //     cout<<suffixMax[i]<<" ";
        //   }
        //    cout<<endl;
        //  for(int i = 0;i<prefixMax.size();i++){
        //     cout<<mini[i]<<" ";
        //   }
        //    cout<<endl;
        // cout<<mini.size()<<endl;
        
       for(int i =0;i<height.size();i++){
            if((mini[i]-height[i]) > 0) {
                ans += (mini[i]-height[i]);
            }
       }

        return ans;
      }
};