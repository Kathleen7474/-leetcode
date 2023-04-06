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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            // cout<<"null left"<<endl;
            return root;
        }   
        else {
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *tmp;
            // cout<<root->left->val;
            tmp = root->left;
            // cout<<tmp->val;
            root->left = root->right;
            root->right = tmp;
        }
        // cout<<"yes left"<<endl;
        return root;
    }
};
