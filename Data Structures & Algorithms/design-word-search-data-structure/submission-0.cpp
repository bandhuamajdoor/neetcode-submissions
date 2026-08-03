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

class WordDictionary {
public:
TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool helperSearch(TrieNode* node, string &word, int pos){
        if(node == nullptr) return false;

        if(pos == word.size()) return node -> endOfWord;
        
        char c = word[pos];
        if(c == '.'){
            for(int i = 0; i < 26; ++i){
                if(helperSearch(node->children[i], word, pos + 1))
                    return true;
            }
        
            return false;
        }
    
        int idx = c - 'a';
        return helperSearch(node->children[idx], word, pos + 1);
    }

    bool search(string word) {
        return helperSearch(root, word, 0);
    }
};
