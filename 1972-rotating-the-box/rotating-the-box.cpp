class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();


        vector<vector<char>> res(m,vector<char>(n));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                res[j][i] = nums[i][j];
            }
        }


        for(auto& el: res){
            reverse(begin(el),end(el));
        }


        for(int i = 0;i<n;i++){
            for(int j = m-1;j>=0;j--){
                if(res[j][i] == '.'){
                    int stoneRow = -1;

                    for(int k = j-1;k>=0;k--){
                        if(res[k][i] == '*'){
                            break;
                        }else if(res[k][i]=='#'){
                            stoneRow = k;
                            break;
                        }
                    }

                    if(stoneRow != -1){
                        res[j][i] = '#';
                        res[stoneRow][i] = '.';
                    }
                }
            }
        }
        return res;
    }
};