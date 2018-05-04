// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ret;
//         std::sort(nums.begin(), nums.end());
//         for(int k = 0; k < nums.size(); ++k){
//             if(nums[k] > 0)
//                 break;
//             int i = k + 1, j = nums.size() - 1;
//             while(i < j){
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if(sum > 0){
//                     j--;
//                 }else if(sum < 0){
//                     i++;
//                 }else{
//                     vector<int> tmp = {nums[i], nums[j], nums[k]};
//                     ret.push_back(tmp);
//                     i++;
//                     j--;
//                     while(nums[i] == nums[i - 1]) i++;
//                     while(nums[j] == nums[j + 1]) j--;
//                 }
//             }
//             while(nums[k + 1] == nums[k]) k++;
//         }
//         return ret;
         vector<vector<int> > res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;
        if(target < 0)
        {
            break;
        }
        while (front < back) {

            int sum = nums[front] + nums[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;

    }
    
    return res;
    }
    
};
