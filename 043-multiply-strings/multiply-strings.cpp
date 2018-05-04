// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size(),n = num2.size();
        string ret(m + n,'0');
        for(int i = m - 1; i >= 0; --i){
            int carry = 0;
            for(int j = n - 1; j >= 0; --j){
                carry =  (ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] -'0') + carry;
                ret[i + j + 1] = carry % 10 + '0';
                carry /= 10;
            } 
            //0 -> number 
            ret[i] += carry;
        }
        if(ret[0] == '0')
            ret = ret.substr(1);
        return ret;
    }
};
