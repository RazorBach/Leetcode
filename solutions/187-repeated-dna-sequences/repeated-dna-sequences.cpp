// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
// Example:
//
//
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
// Output: ["AAAAACCCCC", "CCCCCAAAAA"]
//
//


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.size() <= 10)
            return ret;
        int key = 0, i = 0;
        unordered_map<int, int> hash;
        while(i < 10) {
            key = key << 3 | s[i++] & 7;
        }
        hash[key] = 1;
        while(i < s.size()) {
            key = key << 3 & 0x3fffffff | s[i++] & 7;
            if(hash[key] ++ == 1)
                ret.emplace_back(s.substr(i - 10, 10));
        }
        return ret;
    }
};
