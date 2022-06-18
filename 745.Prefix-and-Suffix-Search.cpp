struct TrieNode {
    TrieNode* arr[27];
    
    int index = -1;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void insert(char ch, TrieNode* newNode = 0) {
        if(!newNode) newNode = new TrieNode();
        arr[ch-'a'] = newNode;
    }
    
    TrieNode* getNext(char ch) {
        return arr[ch - 'a'];
    }
    
    void setIndex(int idx) {
        index = idx;
    }
    
    int getIndex() {
        return index;
    }
};

class WordFilter {
    TrieNode* trie;
public:
    void insert(TrieNode* root, string& s, int idx) {
        for(const char& c : s) {
            if(!root->contains(c)) root->insert(c);
            root = root->getNext(c);
            root->setIndex(idx);
        }
    }
    
    WordFilter(vector<string>& words) {
        trie = new TrieNode();
        
        int idx = 0;
        string s = "";
        
        for(const string& word : words) {
            s = "{" + word;
            insert(trie, s, idx);
            
            for(int i = word.size() - 1; i >= 0; --i) {
                s = word[i] + s;
                insert(trie, s, idx);
            }
            
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* tmp = trie;
        string match = suffix + "{" + prefix;
        for(const char& ch : match) {
            if(!tmp || !tmp->contains(ch)) return -1;
            tmp = tmp->getNext(ch);
        }
        
        return tmp->getIndex();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */