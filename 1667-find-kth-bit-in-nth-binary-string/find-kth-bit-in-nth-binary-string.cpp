class Solution {
public:
    string getsn(int n){
        if(n==1){
            return "0";
        }else if(n==2){
            return "011";
        }
      string st = getsn(n-1);
      string s = st;
     for(char &c : s) c = (c == '0') ? '1' : '0';
      reverse(s.begin(),s.end());
      return st+"1"+s;
    }
    char findKthBit(int n, int k) {
        string st = getsn(n);
        cout<<st<<endl;
        return st[k-1];
    }
};