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
    
    bool isSame(TreeNode* root, TreeNode* subRoot){
        // 要記得處理空的問題
        if(subRoot==nullptr&&root==nullptr)
            return true;
        if(root==nullptr||subRoot==nullptr)
            return false;
        // 有兩種，一種是還在判斷左子右子有沒有相同，另一種是已經確認左子（或右子）裡面有subtree
        bool right_same = false, left_same = false;
        if(root->val==subRoot->val){
            left_same = isSame(root->left, subRoot->left);
            if(left_same){
                right_same = isSame(root->right, subRoot->right);
            }
        }
        if(left_same&&right_same){
            return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr&&root==nullptr)
            return true;
        if(root==nullptr||subRoot==nullptr)
            return false;
        if(isSame(root, subRoot)) 
            return true;
        return (isSubtree(root->left,subRoot)||isSubtree(root->right, subRoot));
    }
};
