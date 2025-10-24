class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> temp;
        for(auto& el : op){
            if(el == "C"){
                if(!temp.empty()){
                    temp.pop_back();
                }
            }
            else if(el == "D"){
                if(!temp.empty()){
                    int val = temp.back();
                    temp.push_back(val*2*1LL);
                }                    
                }else if(el == "+"){
                int n = temp.size();
                if (n >= 2) {
                    temp.push_back(temp[n - 1] + temp[n - 2]);
                } else if (n == 1) {
                    temp.push_back(temp[0]);
                }
                }
                else{
                int val = stoi(el);
                temp.push_back(val);
                }
        }
        int ans = accumulate(temp.begin(),temp.end(),0);
        return ans;
    }
};