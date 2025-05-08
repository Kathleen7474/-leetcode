/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cur_input;
void Traversal(struct TreeNode* root, int* output){
    
    // 好像不會發生？
    if(root==NULL)
        return;
    // printf("cur node %d \n",root->val);
    // printf("cur input %d \n",cur_input);
    // 往左走
    if(root->left!=NULL){
        // printf("go left\n");
        Traversal(root->left, output);
    }
    // output = (int*)realloc(output, cur_input+2 * sizeof(int));
    output[cur_input] = root->val;
    cur_input++;
    // printf("output[cur_input] %d \n",output[cur_input-1]);
    if(root->right!=NULL){
        // printf("go right\n");
        Traversal(root->right, output);
    }
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    cur_input = 0;
    int *output = (int*)malloc(100 * sizeof(int));
    Traversal(root, output);
    int i;
    // for(i = 0;i<cur_input;i++)
    //     printf("i %d = %d\n", i, output[i]);
    *returnSize = cur_input;
    return output;
}
