struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head->next == NULL)
        return NULL;

    int n = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int middle = n / 2;
    temp = head;

    for (int i = 1; i < middle; i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}