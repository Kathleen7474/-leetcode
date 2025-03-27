/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return output;
        }
        cout<<root->val;
        vector<int> tmp;
        tmp.push_back(root->val);
        output.push_back(tmp);
        tmp.clear();
        TreeNode* tmp_node;
        if (root->left != nullptr){
            tmp_node = root->left;
            tmp.push_back(tmp_node->val);
        }
        if (root->right != nullptr){
            tmp_node = root->right;
            tmp.push_back(tmp_node->val);
        }
        if(size(tmp)==0)
            return output; 
        output.push_back(tmp);
        if (root->left != nullptr)
            traversal(root->left, 1);
        if (root->right != nullptr)
            traversal(root->right, 1);
        if (!output.empty() && output.back().empty()) {
            output.pop_back();  // 只有當 back 為 [] 時才刪除
        }
        return output;
    }
private:
    vector<vector<int>> output;
    void traversal(TreeNode* root, int level){
        // vector<int> tmp;
        if (size(output)<level+2){
            output.resize(level + 2);
            output[level+1] = vector<int>(); 
        }

        vector<int>* vec_ptr = &output[level+1];
        TreeNode* tmp_node;
        // tmp = &output[level+1];
        if (root->left != nullptr){
            tmp_node = root->left;
            // cout<<"level "<<level<<endl;
            output[level+1].push_back(tmp_node->val);
        }
        if (root->right != nullptr){
            tmp_node = root->right;
            output[level+1].push_back(tmp_node->val);
        }
        if (root->left != nullptr)
            traversal(root->left, level+1);
        if (root->right != nullptr)
            traversal(root->right, level+1);
        return;
    }
};
