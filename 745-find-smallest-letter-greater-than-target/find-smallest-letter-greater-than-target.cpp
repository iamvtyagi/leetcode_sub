class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0,e = n-1,mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(target >= letters[mid]){
                  s = mid +1;
            }
            else{
                   e = mid -1;
            }
        }
        return letters[s%n];
    }
};