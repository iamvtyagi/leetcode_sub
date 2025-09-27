class Solution {
public:
   double areaOfTriangle(int i ,int j ,int k ,vector<vector<int>>& points){
       return (abs(points[i][0]*(points[j][1]-points[k][1]) + 
            points[j][0]*(points[k][1]-points[i][1])  + 
            points[k][0]*(points[i][1]-points[j][1])))*0.5;
   }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxiArea = -1;
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                     double candidate = areaOfTriangle(i,j,k,points);
                     if(candidate > maxiArea ){
                        maxiArea = candidate;
                     }
                }
            }
        }
        return maxiArea;
    }
};