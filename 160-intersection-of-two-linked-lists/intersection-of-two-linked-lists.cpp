class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // If they don't intersect, both will eventually hit NULL at the same time
        while (ptrA != ptrB) {
            // If ptrA reaches the end, jump to headB
            // Otherwise, just move to the next node
            ptrA = (ptrA == NULL) ? headB : ptrA->next;

            // If ptrB reaches the end, jump to headA
            // Otherwise, just move to the next node
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }

        return ptrA; // This will be the intersection node or NULL
    }
};