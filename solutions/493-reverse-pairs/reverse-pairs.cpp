// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.
//
//


class Solution {
private:
    int mergeSort(vector<int>& nums, int i, int j) {
        //mergeSort nums[i, j]
        if(i >= j)
            return 0;
        int mid = (i + j) / 2;
        int lcnt = mergeSort(nums, i, mid);
        int rcnt = mergeSort(nums, mid + 1, j);
        vector<int> tmp;
        tmp.reserve(j - i + 1);
        int cnt = lcnt + rcnt;
        for(int left = i, leftindex = i, right = mid + 1; left <= mid || right <= j; ) {
            if(right > j || (left <= mid && nums[left] <= nums[right])) {
                tmp.push_back(nums[left++]);
            }else {
                while(leftindex <= mid) {
                    //overflow
                    if((long) nums[leftindex] <= (long) nums[right] * 2l)
                        leftindex++;
                    else
                        break;
                }
                cnt += (mid - leftindex + 1);
                tmp.push_back(nums[right++]);
            }
        }
        std::move(tmp.begin(), tmp.end(), nums.begin() + i);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
