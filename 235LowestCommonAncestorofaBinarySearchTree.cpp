/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr)
            return nullptr;
        if(root->val == p->val||root->val == q->val){
            return root;
        }
        TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_result = lowestCommonAncestor(root->right, p, q);
        if(left_result!=nullptr&&right_result!=nullptr){
            return root;
        }
        else if(left_result!=nullptr){
            return left_result;
        }
        else if(right_result!=nullptr){
            return right_result;
        }
        return nullptr;
    }
};
