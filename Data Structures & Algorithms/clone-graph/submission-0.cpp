/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*, Node*>& mp){
        if(node == nullptr) return nullptr;
        if(mp.find(node) != mp.end()) return mp[node];

        Node* temp = new Node(node -> val);
        mp[node] = temp;
        Node* temp1;
        for(const auto& adj: node -> neighbors){
            temp1 = solve(adj, mp);
            temp -> neighbors.push_back(temp1); 
        }
        return temp;
    }
  
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        return solve(node, mp);
    }
};
