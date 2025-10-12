class Solution {
public:
    void helper(vector<char>& s,int i , int j ){
         if(i>=j){
            return;
         }
         swap(s[i++],s[j--]);
         helper(s,i,j);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        helper(s,0,n-1);
    }
};