class Solution {
public:
    
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 1;i<n;i++){
            string w1 = words[i-1];
            string w2 = words[i];
            sort(w1.begin(),w1.end());
              sort(w2.begin(),w2.end());
            if(w1 == w2){
                swap(words[i-1],words[i]);
                 words[i-1] = "-1";
            }
        }
        for(int i = 0;i<n;i++){
             if(words[i] != "-1"){
                 ans.push_back(words[i]);
             }
        }
        return ans;
    }
};