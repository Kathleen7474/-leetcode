/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    // node的建構子。有三種
    Node() {  //不賦值的話val = 0, neighbor為空，後面應該就看懂了
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
    Node* cloneGraph(Node* node) {
        if (node==nullptr){
            return nullptr;
        }
        // clone 1
        Node* new_node = new Node(node->val);
        all_node[node->val] = new_node;
        for (Node *neighbor_node : node->neighbors){
            // cout<<"neightbor value "<<neighbor_node->val<<endl;
            Node* new_node_in_loop;
            if(all_node.find(neighbor_node->val)==all_node.end()){ 
                new_node_in_loop = cloneGraph(neighbor_node);
            }
            else{
                new_node_in_loop = all_node[neighbor_node->val];
            }
            new_node->neighbors.push_back(new_node_in_loop);
        }
        return new_node;
    }
private: 
    map<int, Node*> all_node;
};
