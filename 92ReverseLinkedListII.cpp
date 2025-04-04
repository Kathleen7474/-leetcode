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
    ListNode *right_child;
    ListNode *right_node;
    int left, right;
    ListNode* reverse(ListNode* head, int cnt){

        if(cnt == right){
            right_child = head->next;
            right_node = head;
            return head;
        }

        ListNode *Node = reverse(head->next, cnt+1);

        // 中間的
        if(cnt>left&&cnt<right){
            Node->next = head;
        }
        
        // 這是在最後的時候才用
        if(cnt == left){
            Node->next = head;
            head->next = right_child;
            if(cnt==1){
                return right_node;
            }
        }
        if(cnt+1 == left){
            head->next = right_node;
        }

        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int in_left, int in_right) {
        if(in_left==in_right)
            return head;
        left = in_left;
        right = in_right;
        head = reverse(head, 1);
        return head;
    }
};
