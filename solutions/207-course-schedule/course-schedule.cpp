// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
//
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
//
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> indegree = compute_indegree(numCourses, graph);
        for(int j = 0; j < numCourses; ++j){
            int i = 0;
            for(; i < numCourses; ++i) {
                if(0 == indegree[i]) break;
            }
            if(i == numCourses) return false;
            indegree[i] = -1;
            for(auto adpoint : graph[i]) {
                indegree[adpoint]--;
            }
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(const int numCourses,vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        for(auto edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        return graph;
    }
    
    vector<int> compute_indegree(const int numCourses,const vector<unordered_set<int>>& graph) {
        vector<int> indegree(numCourses);
        for(auto ad_set : graph)
            for(auto id : ad_set) {
                indegree[id]++;
            }
        return indegree;
    }
};
