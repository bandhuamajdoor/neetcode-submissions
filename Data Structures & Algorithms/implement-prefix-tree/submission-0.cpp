class TrieNode{
public:
    bool endOfWord;
    TrieNode* children[26];

    TrieNode(){
        endOfWord = false;
        for(int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;
    
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
    
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c: prefix){
            int index = c - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
    
        return true;
    }
};
