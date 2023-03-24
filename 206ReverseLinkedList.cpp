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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *rev_list;
        ListNode *cur;
        
        cur = head;
        bool start = true;
        while(cur != 0){
            if (start==true) {
                rev_list = new ListNode();
                rev_list->next = NULL;
                rev_list->val = cur->val;
            }
            else{
                ListNode *new_node = new ListNode();
                new_node->val = cur->val;
                new_node->next = rev_list;
                rev_list = new_node;
            }
            start = false;
            cur = cur->next;
        }
        return rev_list;
    }
};
