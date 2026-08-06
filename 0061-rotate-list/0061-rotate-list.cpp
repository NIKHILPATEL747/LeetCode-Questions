class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int size = 1;
        ListNode* curr = head;
        while (curr->next) {
            size++;
            curr = curr->next;
        }

        curr->next = head;
        k = k % size;
        int stepsToNewHead = size - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
