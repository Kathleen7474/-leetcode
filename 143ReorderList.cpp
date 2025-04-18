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
    void reorderList(ListNode* head) {
        vector<ListNode*> L_vec;
        ListNode* cur = head;
        while(cur!=nullptr){
            L_vec.push_back(cur);
            cur = cur->next;
        }
        for(int i = 0;i<L_vec.size()/2;i++){
            L_vec[i]->next = L_vec[L_vec.size()-1-i];
            if(i==L_vec.size()/2-1&&L_vec.size()%2==0){
                L_vec[L_vec.size()-1-i]->next = nullptr;
                break;
            }
            L_vec[L_vec.size()-1-i]->next = L_vec[i+1];
            if(i==L_vec.size()/2-1&&L_vec.size()%2==1){
                L_vec[L_vec.size()-1-i]->next->next = nullptr;
            }
        }
    }
};
