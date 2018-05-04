// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m(matrix.size()) , n(matrix[0].size());  
        int p(0),q(m * n - 1);
        while(p <= q){
            int mid = (p + q) / 2;
            int midTemp = matrix[mid / n][mid % n];
            if(target > midTemp)
                p = mid + 1;
            else if(target < midTemp)
                q = mid - 1;
            else
                return true;
        }
        return false;
    }
};
