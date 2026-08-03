class TrieNode{
public:
    string word;
    TrieNode* children[26];

    TrieNode(){
        word = "";
        for(int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
    
        node->word = word;
    }

    // bool search(string word){
    //     TrieNode* node = root;
    //     for(char c: word){
    //         int index = c - 'a';
    //         if(!node->children[index]) return false;
    //         node = node->children[index];
    //     }
    
    //     return true;
    // }
};

class Solution {
public:
vector<string> ans;
    void dfs(int i, int j, TrieNode* node, vector<vector<char>>& board){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        
        char ch = board[i][j];
        if(ch == '#') return;

        node = node->children[ch - 'a'];
        if(!node) return;

        if(!node->word.empty()){
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k = 0; k < 4; ++k){
            int nr = i + dx[k];
            int nc = j + dy[k];
            dfs(nr, nc, node, board);
        }
    
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie ptree;
        for(const string& word: words){
            ptree.insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(ptree.root->children[board[i][j] - 'a'])
                    dfs(i, j, ptree.root, board);
            }
        }
    
        return ans;
    }
};
