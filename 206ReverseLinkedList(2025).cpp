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
    ListNode *final_output;
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        traversal(head);
        return final_output;
    }
    ListNode* traversal(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        // 最後的頭
        ListNode *parent = traversal(head->next);
        if(parent==nullptr){
            final_output = head;
        }
        else{
            parent->next = head;
        }
        head->next = nullptr;
        return head;
    }
    
};
