class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        stack <int> num;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])) {
                string a;
                while(i<s.length() && isdigit(s[i])){
                    a+=s[i];
                    i++;
                } 
                num.push(stoi(a));
                i--;
            }
            else if(s[i]==']'){
                string a, b;
                while(st.top()!="["){
                    a = st.top()+a;
                    st.pop();
                }
                st.pop();
                for(int j=0; j<num.top(); j++) b+=a;
                num.pop();
                st.push(b);
            }
            else st.push(string(1, s[i]));
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};