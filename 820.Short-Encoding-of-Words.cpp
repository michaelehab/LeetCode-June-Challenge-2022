struct TrieNode{
    TrieNode* arr[27];
    
    bool contains(char c){
        return (arr[c-'a'] != NULL);
    }
    
    void insert(char ch, TrieNode* newNode = 0) {
        if(!newNode) newNode = new TrieNode();
        arr[ch-'a'] = newNode;
    }
    
    TrieNode* getNext(char ch) {
        return arr[ch - 'a'];
    }
    
};

class Encoder{
    public:
    TrieNode* root;
    
    Encoder(vector<string>& words, int& ans){
        root = new TrieNode();
        for(string& x : words) insert(x);
        solve(ans, root);
    }
    
    void insert(string& word){
        TrieNode* node = root;
        for(int i = word.size() - 1; i >= 0; --i){
            if(!node->contains(word[i])) node->insert(word[i]);
            node = node->getNext(word[i]);
        }
    }
    
    void solve(int& ans, TrieNode* node, int c = 0){
        bool flag = false;
        for(int i = 0; i < 26; i++){
            if(node->arr[i]){
                solve(ans, node->getNext('a' + i), c + 1);
                flag = true;
            }
        }
        if(!flag) ans += (c + 1);
    }   
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        Encoder e(words, ans);
        return ans;
    }
};