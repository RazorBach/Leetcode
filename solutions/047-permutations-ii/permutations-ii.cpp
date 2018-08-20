// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do{
            ret.push_back(nums);
        }while(_next(nums));
        return ret;
    }
private:
    bool _next(vector<int>& nums){
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
                swap(nums[i], nums[k]);
                break;
            }
        }
        reverse(nums.begin() + k + 1, nums.end());
        return true;
    }
};
