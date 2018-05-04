// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
//
// Example 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    typedef vector<int>::size_type iSize;
    
    //找到nums1+nums2序列的第k个数 递归
    double getK(vector<int>& nums1,vector<int>& nums2,iSize p1,iSize m,iSize p2,iSize n,iSize k){
       if (m > n)
		//让短的vector放在前面 方便后面判断x y
		    return getK(nums2, nums1, p2, n, p1, m, k);
	    if (m == 0)
		    return nums2[p2 + k - 1];
        if (k == 1)
            return min(nums1[p1], nums2[p2]);
        iSize x = min(k / 2, m);
        iSize y = k - x;
        if (nums1[p1 + x - 1] < nums2[p2 + y - 1]) {
            //放弃nums1[p1,p1+x-1]段
            return getK(nums1, nums2, p1 + x, m - x, p2, n, k - x);
        }
        else if (nums1[p1 + x - 1] > nums2[p2 + y - 1]) {
            //放弃nums2[p2,p2+y-1]段
            return getK(nums1, nums2, p1, m, p2 + y, n - y, k - y);
        }
        else {
            return nums1[p1 + x - 1];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        iSize k = nums1.size() + nums2.size();
        if( k % 2 == 1){
           return getK(nums1,nums2,0,nums1.size() ,0,nums2.size(),k/2 + 1);
        }else if( k % 2 == 0){
           return (getK(nums1,nums2,0,nums1.size() ,0,nums2.size(),k/2)+getK(nums1,nums2,0,nums1.size(),0,nums2.size(),k /2 +1))/2;
        }
    }
};
