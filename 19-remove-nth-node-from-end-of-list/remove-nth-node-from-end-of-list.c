/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (count == n)
    {
        return head->next;
    }

    count = count - n;
    temp = head;

    for (int i = 1; i < count; i++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}