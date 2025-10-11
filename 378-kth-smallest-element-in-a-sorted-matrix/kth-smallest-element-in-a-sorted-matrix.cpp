class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxh;
        int n = matrix.size();
        for(int i =0;i<n;i++){
             for(int j = 0;j<matrix[i].size();j++){
                  if(maxh.size() < k){
                      maxh.push(matrix[i][j]);
                  }else{
                     maxh.push(matrix[i][j]);
                     maxh.pop();
                  }
             }
        }
        return maxh.top();
    }
};