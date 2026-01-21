class Solution {
public:
    int secondHighest(string s) {
        int n = s.size();
        int first = -1;
        int second = -1;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                int d = ch - '0';
                if(d> first ){
                    second = first;
                    first = d;
                }
                else if(d < first && d > second){
                    second = d;
                }
            }
        }
        return second;
    }
};