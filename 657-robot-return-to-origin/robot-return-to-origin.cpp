class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0;i<moves.size();i++){
            char ch = moves[i];
            if(ch=='L') cnt1++;
            if(ch=='R') cnt1--;
            if(ch=='U') cnt2++;
            if(ch=='D') cnt2--;
        }
        return (cnt1==0 && cnt2==0);
    }
};