class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0;
        int i2 = 0;
        while(i1 < version1.size() && i2 < version2.size()){
             string s1 = version1.substr(i1, version1.size() - i1);
             string s2 = version2.substr(i2, version2.size() - i2);

             int k1 = s1.find('.');
             if(k1 == string::npos) k1 = s1.size();
             int k2 = s2.find('.');
             if(k2 == string::npos) k2 = s2.size();

             int a = stoi(s1.substr(0, k1));
             int b = stoi(s2.substr(0, k2));

             if(a < b){
                return -1;
             } else if(a > b){
                return 1;
             }

             i1 += k1 + 1;
             i2 += k2 + 1;
        }

        while(i1 < version1.size()){
            string s1 = version1.substr(i1, version1.size() - i1);
            int k1 = s1.find('.');
            if(k1 == string::npos) k1 = s1.size();
            int a = stoi(s1.substr(0, k1));
            if(a > 0){
                return 1;
            }
            i1 += k1 + 1;
        }

        while(i2 < version2.size()){
            string s2 = version2.substr(i2, version2.size() - i2);
            int k2 = s2.find('.');
            if(k2 == string::npos) k2 = s2.size();
            int b = stoi(s2.substr(0, k2));
            if(b > 0){
                return -1;
            }
            i2 += k2 + 1;
        }

        return 0;
    }
};
