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
    int end_cnt, remove_node;
    ListNode* Traversal(ListNode* head) {
        //如果我是結尾
        if(head->next == nullptr){
            end_cnt = 1;
            // 如果我同事時結尾又是cut
            if(end_cnt == remove_node)
                return nullptr;
            else   
                return head;
        }
        ListNode *next_node = Traversal(head->next);
        // 如果我前一個是cut
        if(end_cnt == remove_node){
            head->next = next_node;
        }
        end_cnt++;
        // 如果我是cut
        if(end_cnt == remove_node){
            return next_node;
        }
        return head;        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        remove_node = n;
        head = Traversal(head);
        return head;
    }
};
