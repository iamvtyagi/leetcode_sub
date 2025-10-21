class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i = n - 1;
        int j = m - 1;
        int carry = 0;
        string res = "";

        while(i >= 0 && j >= 0) {
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
            i--;
            j--;
        }

        while(i >= 0) {
            int a = num1[i] - '0';
            int sum = a + carry;
            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
            i--;
        }

        while(j >= 0) {
            int b = num2[j] - '0';
            int sum = b + carry;
            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
            j--;
        }

        if(carry > 0) {
            res = to_string(carry) + res;
        }

        return res;
    }
};
