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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode *head ;
         ListNode *cur = head;
         bool start = true;
         while(list1!=0&&list2!=0){
             int a = list1->val;
             int b = list2->val;
            //  cout<<a<<" "<<b<<endl;
             ListNode *new_list_node = new ListNode();
             if(a>=b){
                new_list_node->val = b;
                if(start==true){
                    start = false;
                    head = list2;
                    cur = head;
                }
                else{
                    cur->next = new_list_node;
                    cur = cur->next;
                }
                list2 = list2->next;
             }
            else if(a<b){
                new_list_node->val = a;
                if(start==true){
                    start = false;
                    head = new_list_node;
                    cur = head;
                }
                else{
                    cur->next = new_list_node;
                    cur = cur->next;
                }
                list1 = list1->next;
            }
            
         }
         
         if(list1!=0){
             if(start==true){
                 head = list1;
             }else
             {cur->next = list1;}
         }else if(list2!=0){
             if(start==true){
                head = list2;
             }else
             {cur->next = list2;}
         }else{
             head = list1;
             return head;
         }
        cur = head;
        while(cur!=0){
            // cout<<cur->val<<endl;
            cur = cur->next;
        }
        return head;
    }
};
