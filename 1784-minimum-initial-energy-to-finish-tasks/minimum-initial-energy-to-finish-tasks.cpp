class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[&](vector<int>&x,vector<int>&y){
            return x[1]-x[0]>y[1]-y[0];
        });
        int curr=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(curr<tasks[i][1]){
                temp+=tasks[i][1]-curr;
                curr=tasks[i][1];
            }
            curr-=tasks[i][0];
        }
        return temp;
    }
};