// COPIED SOLUTION since i don't know trie data structure and its on my list to learn 

class TrieNode{
    public:
    bool leaf;
    TrieNode* child[26];
};

class StreamChecker {
public:
    TrieNode* root;
    vector<TrieNode*> paths;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(string word:words) {
            TrieNode *it = root;
            for(char c :word) {
                if(!it->child[c-'a']) {
                    it->child[c-'a'] = new TrieNode();
                }
                it = it->child[c-'a'];
            }
            it->leaf = true;
        }
    }
    
    bool query(char letter) {
        bool result = false;
        vector<TrieNode*> newpaths;
        paths.push_back(root);
        
        for(TrieNode* it : paths) {
            TrieNode* node = it->child[letter - 'a'];
            if(node) {
                if(node->leaf)result = true;
                newpaths.push_back(node);
            }
        }
        paths = move(newpaths);
        return result;
    }
};