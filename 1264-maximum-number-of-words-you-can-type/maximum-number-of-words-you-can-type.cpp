class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        bool check = false;
        int cnt = 0;
        string mask = " ";
        for(int i = 0;i<n;i++){
            if(brokenLetters.find(text[i]) != string::npos){
                    check = true;
            }
            if((mask.find(text[i]) != string::npos ) && check == false){
                    cnt++;
            }
            if((mask.find(text[i]) != string::npos ) && check == true){
                    // cnt++;
                    check = false;
            }
        }
        if(check == false) cnt++;
        return cnt;
    }
};