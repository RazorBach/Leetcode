// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        dfs(ret, "", s, 0, 0);
        return ret;
    }
    void dfs(vector<string>& v,string ip,string s,int start,int step){
        if(start == s.size() && step == 4){
            ip.erase(ip.size() - 1);
            v.push_back(ip);
            return;
        }
        if(s.size() - start > 3 * (4 - step)) return;
        if(s.size() - start < (4 - step)) return;
        int num = 0;
        // if(s[start] == '0'){
        //     ip += '0';
        //     dfs(v, ip + '.', s, start + 1, step + 1);
        //     return;
        // }
        for(int i = start; i < start + 3; ++i){
            num = 10*num + (s[i] - '0');
            if(num <= 255){
                ip += s[i];
                dfs(v, ip + '.', s, i + 1, step + 1);
            }
            
            if(num==0) break;
        }
    }
};
