class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        long long ans = 0;  
        
        while(i < j){
            int mini = min(height[i], height[j]);
            long long width = j - i;  
            long long area = 1LL * mini * width;
            ans = max(ans, area);

            // move the smaller height pointer
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return (int)ans; 
    }
};
