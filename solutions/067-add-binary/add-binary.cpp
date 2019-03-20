// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int i(a.size()),j(b.size()),add(0);
        while(i || j || add){
            add += i ? a[--i] - '0': 0;
            add += j ? b[--j] - '0': 0;
            ret = char(add % 2 + '0') + ret;
            add /= 2;
        }
        return ret;
       
    }
};
