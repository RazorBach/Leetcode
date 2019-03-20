// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do{
            ret.push_back(nums);
        }while(next_permutation(nums));
        return ret;
    }
private:
    bool next_permutation(vector<int>& nums){
        int k = -1;
        for(int i = nums.size() - 1; i > 0; --i){
            if(nums[i - 1] < nums[i]){
                k = i - 1;
                break;
            }
        }
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return false;
        }
        for(int i = nums.size() - 1; i > k; --i){
            if(nums[i] > nums[k]){
                swap(nums[k], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + k + 1, nums.end());
        return true;
    }
};
