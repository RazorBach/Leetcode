// Find the total area covered by two rectilinear rectangles in a 2D plane.
//
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//
//
// Example:
//
//
// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45
//
// Note:
//
// Assume that the total area is never beyond the maximum possible value of int.
//


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        //check if overlap
        int lbx = max(A, E);
        int lby = max(B, F);
        int rux = min(C, G);
        int ruy = min(D, H);
        int overlap = 0;
        if(lbx < rux && lby < ruy)
            overlap = (rux - lbx) * (ruy - lby);
        return area1 - overlap + area2 ;
    }
};
