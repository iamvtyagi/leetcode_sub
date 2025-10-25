class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string smallest = s;
        for(int i= 1;i<=n;i++){
            string copyy = s;
            reverse(copyy.begin(),copyy.begin()+i);
            if(copyy < smallest)  smallest = copyy;
            copyy = s;
            reverse(copyy.end()-i,copyy.end());
            if(copyy < smallest) smallest = copyy;
        }
        return smallest;
    }
};