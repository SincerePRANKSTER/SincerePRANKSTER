/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if (head == NULL || k == 1)
        return head;

    int n = 0;
    struct ListNode* temp = head;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    int limit = n - (n % k);

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* groupPrev = &dummy;

    int count = 0;

    while (count < limit)
    {
        struct ListNode* groupStart = groupPrev->next;

        struct ListNode* prev = NULL;
        struct ListNode* curr = groupStart;

        for (int i = 0; i < k; i++)
        {
            struct ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        groupPrev->next = prev;
        groupStart->next = curr;
        groupPrev = groupStart;

        count += k;
    }

    return dummy.next;
}