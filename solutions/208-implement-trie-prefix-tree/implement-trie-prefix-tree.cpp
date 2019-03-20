// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class Node {
public:
    Node(bool b = false):is_word(b) {
        //set pointer nullptr
        memset(next, 0, sizeof(next));
    }
    bool is_word;
    //represent the next charater from 'a' to 'z'
    Node* next[26];
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for(char c : word) {
            if(!cur->next[c - 'a'])
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for(char c : word) {
            if(!cur->next[c - 'a'])
                return false;
            cur = cur->next[c - 'a'];
        }
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c : prefix) {
            if(!cur->next[c - 'a'])
                return false;
            cur = cur->next[c - 'a'];
        }
        return true;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
