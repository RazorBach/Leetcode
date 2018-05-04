//
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//
//
// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        static vector<int> tmp{0};
        while(tmp.size() <= n) {
            int m = tmp.size();
            int cnt = INT_MAX;
            for(int i = 1; i * i <= m; ++i) {
                cnt = min(cnt, tmp[m - i * i] + 1);
            }
            tmp.push_back(cnt);
        }
        return tmp[n];
    }
};
