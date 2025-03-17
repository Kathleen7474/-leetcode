/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        TreeNode *cur_found;
        vector<TreeNode*> target_vec;
        DFS(head->val, root, target_vec);
        
        ListNode* tail = head->next;
        // 比對所有可能的樹
        cout<<endl;
        for(int i=0;i<target_vec.size();i++){
            TreeNode *cur_root = target_vec[i];
            bool result = traversal(head, cur_root);
            if (result)
                return true;
        }
        return false;
    }
private: 
    bool traversal(ListNode* head, TreeNode* root){
        if (root==nullptr)
            return false;
        cout<<"traversal "<<root->val<<" "<<head->val<<endl;
        if (root->val != head->val)
            return false;
        else{
            if (head->next==nullptr)
                return true;
            else if (traversal(head->next, root->left)){
                return true;
            }
            else 
                return traversal(head->next, root->right);
        } 
    }
    void DFS(int target, TreeNode* root, vector<TreeNode*> &target_vec){
        if (root == nullptr) {
            return;
            cout<<"null"<<endl;
        } else
            cout<<"root "<<root->val;
        if (target == root->val)
            target_vec.push_back(root);
        DFS(target, root->left, target_vec);
        DFS(target, root->right, target_vec);
        return;
    }
};
