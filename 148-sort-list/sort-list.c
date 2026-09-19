#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

struct ListNode* sortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Count nodes
    int n = 0;
    struct ListNode* temp = head;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    // Create array
    int* arr = malloc(n * sizeof(int));

    // Copy values
    temp = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->val;
        temp = temp->next;
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    // Put sorted values back
    temp = head;

    for (int i = 0; i < n; i++)
    {
        temp->val = arr[i];
        temp = temp->next;
    }

    free(arr);

    return head;
}