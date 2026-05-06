class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        unordered_set<string> st({"+", "-", "*", "/"});

        stack<int> s;

        for(int i = 0;i<n;i++){

            if(st.find(tokens[i]) != st.end()){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                string ch = tokens[i];
                int curr ;
                if(ch == "+"){
                    curr = b + a;
                }else if(ch == "-"){ curr =  b - a;}
                else if(ch == "*"){  curr = b*a;}
                else { curr = b/a;}

                s.push(curr);
            }else{
                int val = stoi(tokens[i]);
                s.push(val);
            }
        }
        return s.top();
    }
};