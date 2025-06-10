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
    int lr = -1;
    void findeNewHome(TreeNode* root, TreeNode* insert){
        if(insert->val<root->val){
            if(root->left==nullptr)
                root->left = insert;
            else
                findeNewHome(root->left, insert);
        }else{
            if(root->right==nullptr)
                root->right = insert;
            else
                findeNewHome(root->right, insert);
        } 
        return;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return nullptr;
        if(key==root->val){
            // 沒有任何child
            if(root->left==nullptr&&root->right==nullptr){
                return nullptr;
            }

            // 只有一個child
            // only right
            if(root->left==nullptr&&root->right!=nullptr){
                return root->right;
            // only left
            }else if(root->left!=nullptr&&root->right==nullptr){
                return root->left;
            }
            // 好像不用限定tree root case反正做一樣的事情？

            // 同時有左右子樹
            else{
                findeNewHome(root->left, root->right);
                return root->left;
            }

        }
        else if(key<root->val){
            if(root->left==nullptr)
                return root;
            lr = 0;
            TreeNode* new_child = deleteNode(root->left, key);
            root->left = new_child;
        }
        else{
            if(root->right==nullptr)
                return root;
            lr = 1;
            TreeNode* new_child = deleteNode(root->right, key);
            root->right = new_child;
        }
        return root;
    }
};
