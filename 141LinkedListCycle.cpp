/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast= head;
        bool start = true;
        while(slow !=0&&fast!=0){
            if(start == true){
                if(head->next==0||head->next->next==0) {
                    return false;
                }
            }
            else{
                if (slow==fast) {
                    return true;
                }
            }
            slow = slow->next;
            if(fast->next==0)return false;
            fast = fast->next->next;
            start = false;
        }
        cout<<"end"<<endl;


        return false;
    }
};
