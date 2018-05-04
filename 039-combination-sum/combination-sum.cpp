// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        backtrace(candidates, tmp, ret, 0, target);
        return ret;
    }
private:
    void backtrace(vector<int>& candidates, vector<int>& tmp, vector<vector<int>>& ret,int begin, int target ) {
        if(target == 0){
            ret.emplace_back(tmp);
            return;
        }
        if(target < 0)
            return;
        for(int i = begin; i < candidates.size(); ++i) {
            tmp.push_back(candidates[i]);
            backtrace(candidates, tmp, ret, i, target - candidates[i]);
            tmp.pop_back();
        }
    }
    
};
