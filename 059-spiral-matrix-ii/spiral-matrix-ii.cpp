// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(!n) return vector<vector<int>>();
        vector<vector<int>> matrix(n, vector<int>(n , 0));
        int cnt = 1 , m = n , d = 0, num = n * n;
        for(int i = 0; i < n; ++i)
            matrix[0][i] = cnt++;
        int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int pos[2] = {0, n - 1};
        while(cnt <= num){
            for(int i = 1; i < m; ++i){
                pos[0] += dir[d][0];
                pos[1] += dir[d][1];
                matrix[pos[0]][pos[1]] = cnt++;
            }
            swap(--m, n);
            d = (d + 1) % 4;
        }
        return matrix;
    }
};
