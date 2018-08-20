// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            int cnt1 = 0, cnt2 = 0, a=0, b=1;
    
    for(auto n: nums){
        if (a==n){
            cnt1++;
        }
        else if (b==n){
            cnt2++;
        }
        else if (cnt1==0){
            a = n;
            cnt1 = 1;
        }
        else if (cnt2 == 0){
            b = n;
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = cnt2 = 0;
    for(auto n: nums){
        if (n==a)   cnt1++;
        else if (n==b)  cnt2++;
    }
    
    vector<int> res;
    if (cnt1 > nums.size()/3)   res.push_back(a);
    if (cnt2 > nums.size()/3)   res.push_back(b);
    return res;
    }
};
