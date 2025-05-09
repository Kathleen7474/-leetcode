/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int cur_idx;
int k;
int Traversal(struct TreeNode* root){
    int return_value = -1;
    // 好像不會發生？
    if(root==NULL)
        return -1;
    // 往左走
    if(root->left!=NULL){
        // printf("go left\n");
        return_value = Traversal(root->left);
    }
    if(return_value!=-1)
        return return_value;
    if(cur_idx==k)
        return root->val;
    cur_idx++;
    if(root->right!=NULL){
        // printf("go right\n");
        return_value = Traversal(root->right);
    }
    return return_value;
}
int kthSmallest(struct TreeNode* root, int input_k) {
    cur_idx = 1;
    k = input_k;
    return Traversal(root);
}
