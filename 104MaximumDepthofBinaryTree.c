/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int left_depth = 0;
    int right_depth = 0;
    // 如果為空
    if (!root){
        printf("null\n");
        return 0;
    }
    printf("not null %d\n",root->val);
    left_depth = maxDepth(root->left);
    right_depth = maxDepth(root->right);
    printf("val %d, left depth %d, right depth %d\n",root->val, left_depth, right_depth);
    if (left_depth > right_depth){
        left_depth++;
        return left_depth;
    }
    else {
        printf("return right \n");
        right_depth++;
        return right_depth;
    }
}
