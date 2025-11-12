class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        vector<string> s;
        string curr = "";
        int ptr = 0;
        bool check = true;
        while(ptr<n){
            if(check){
                check = false;
                curr += "a";
                s.push_back(curr);
                continue;
            }

            if(curr[ptr] != target[ptr]){
                 curr[ptr] = (curr[ptr]-'a') + 1 + 'a';
                s.push_back(curr);
            }else{
                curr += "a";
                s.push_back(curr);
                ptr++;
            }
        }
        return vector<string>(s.begin(),s.end()-1);
    }
};