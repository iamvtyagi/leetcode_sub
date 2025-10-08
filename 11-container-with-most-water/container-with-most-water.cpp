class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int area = INT_MIN;
        while(i<=j){
            int x = min(height[i],height[j]);
            area = max(x*(j-i) , area);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};