// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//


class Solution {
private:
    void mergeSort(vector<int>& index, vector<int>& nums, vector<int>& cnt, int i, int j) {
        //index array storages the true indexes of value
        //merge nums[i, mid - 1] & nums[mid, j], calculate Reverse order
        if(i >= j)
            return;
        int mid = (i + j + 1)/ 2;
        mergeSort(index, nums, cnt, i, mid - 1);
        mergeSort(index, nums, cnt, mid, j);
        vector<int> tmp(j - i + 1, 0);
        int left = i, right = mid, cur = 0, rightcnt = 0;
        while(left < mid || right <= j) {
            if(right > j || (left < mid && nums[index[left]] <= nums[index[right]])) {
                tmp[cur] = index[left];
                cnt[index[left]] += rightcnt;
                left++;
            }else {
                //nums[index[left]] > nums[index[right]]
                rightcnt++;
                tmp[cur] = index[right];
                right++;
            }
            cur++;
        }
        move(tmp.begin(), tmp.end(), index.begin() + i);
        
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int s = nums.size();
        vector<int> cnt(s, 0);
        vector<int> index(s, 0);
        iota(index.begin(), index.end(), 0);
        mergeSort(index, nums, cnt, 0, s - 1);
        return cnt;
    }
};
