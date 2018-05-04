// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Example 1:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
//
//
// Example 2:
//
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
//
//


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct hashfunc {
    size_t operator() (const pair<int,int>& l) const {
        return l.first ^ l.second; 
    }
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ret = 0;
        for(int i = 0; i < points.size(); ++i) {
            int same = 1, imax = 0;
            unordered_map< pair<int, int> , int, hashfunc> hash;
            for(int j = i + 1; j < points.size(); ++j) {
                if(points[j].x == points[i].x && points[j].y == points[i].y) {
                    same++;
                }else {
                    int dx = points[i].x - points[j].x;
                    int dy = points[i].y - points[j].y;
                    int g = GCD(dx, dy);
                    dx /= g;
                    dy /= g;
                    imax = max(imax, ++hash[make_pair(dx, dy)]);
                }
            }
            ret = max(ret, imax + same);
        }
        return ret;
    }
private:
    int GCD(int a, int b) {
        if(b==0) return a;
        else return GCD(b, a%b);
    }
};
