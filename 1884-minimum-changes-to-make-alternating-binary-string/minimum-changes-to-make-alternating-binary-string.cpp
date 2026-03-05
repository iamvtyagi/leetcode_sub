class Solution {
public:
    int helper(int k,string& s){
        int cnt = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='0'){
                if(k==1){cnt++;}
            }
            if(s[i]=='1'){
                if(k==0){cnt++;}
            }
            k = !(k);
        }
        return cnt;
    }
    int minOperations(string s) {
        int n = s.size();
        int mini = min(helper(0,s),helper(1,s));
        return mini;
    }
};