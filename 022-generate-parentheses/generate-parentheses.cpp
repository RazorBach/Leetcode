//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        addPar(ret, n, 0, string(""));
        return ret;
    }
private:
    void addPar(vector<string>& v, int m, int n, string str){
        if(m == 0 && n == 0){
            v.push_back(str);
            return;
        }
        if(m > 0){
            addPar(v, m - 1, n + 1, str + '(');
        }
        if(n > 0){
            addPar(v, m, n - 1, str + ')');
        }
    }
};
