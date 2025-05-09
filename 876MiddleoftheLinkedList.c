/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int total;
struct ListNode* findMiddleNode(struct ListNode* head) {
    int node_num = total;
    struct ListNode* return_node;
    if(head->next!=NULL){
        total++;
        return_node = findMiddleNode(head->next);
    }else if (total==0||total ==1)
        return head;
    else
        return NULL;
    // 如果我是中間node
    // printf("node num %d, total %d \n", node_num, total);
    if(node_num == total/2+total%2)
        return head;
    // 否則return別人
    else return return_node;
}
struct ListNode* middleNode(struct ListNode* head) {
    total = 0;
    struct ListNode* return_node;
    return_node = findMiddleNode(head);
    return return_node;
}
