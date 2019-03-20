// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


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
