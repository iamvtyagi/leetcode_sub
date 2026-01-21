class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;

        for(char ch : s){
            if(ch >= '0' && ch <= '9'){
                int d = ch - '0';

                if(d > first){
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
