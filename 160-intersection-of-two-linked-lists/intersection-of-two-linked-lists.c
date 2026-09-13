/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* heada, struct ListNode* headb) {
    struct ListNode* a = heada;
    struct ListNode* b = headb;

    while (a != b) {
        a = (a == NULL) ? headb : a->next;
        b = (b == NULL) ? heada : b->next;
    }

    return a;
}