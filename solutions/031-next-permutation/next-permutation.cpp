// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(!n) return;
        int i = n - 2;
        while(i >= 0){
            if(nums[i] < nums[i+1])
                break;
            i--;
        }
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        } 
        for(int j = n - 1; j >= i;--j){
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i + 1,nums.end());
    }
};
