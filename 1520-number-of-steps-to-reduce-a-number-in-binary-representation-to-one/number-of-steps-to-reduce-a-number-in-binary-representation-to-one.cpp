class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s != "1"){
            if(s.back() == '0'){
                //even no case last bit '0'
                s.pop_back();
            }else{
                //odd no case last bit '1'

                int i = s.size()-1;
                // handling carry
                while(i>=0 && s[i]=='1'){
                    s[i] = '0';
                    i--;
                }

                if(i>=0){
                    s[i]= '1';
                }else{
                    // if sb 1 ho 
                    s = "1" + s;
                }
            }
            cnt++;
        }
        return cnt;
    }
};