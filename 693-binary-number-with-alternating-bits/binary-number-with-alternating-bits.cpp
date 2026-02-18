class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1); 
        // like yrr 5 jaise 101 hai to n>>1 hoga 010 
        // eske baad dono ka xor (101)^(010) = 111 agar sb 1 aayega means alternating hai 
        return (x & (x + 1)) == 0;
        // it checks ki sb 1 h ki nhi 
    }
};