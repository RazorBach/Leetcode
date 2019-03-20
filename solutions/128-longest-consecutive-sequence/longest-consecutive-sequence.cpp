// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> hash;
        for(int i : nums) {
            if(hash[i])
                continue;
            int left = hash[i - 1];
            int right = hash[i + 1];
            int len = left + right + 1;
            hash[i] = len;
            ret = std::max(ret, len);
            hash[i - left] = len;
            hash[i + right] = len;
        }
        return ret;
    }
};
