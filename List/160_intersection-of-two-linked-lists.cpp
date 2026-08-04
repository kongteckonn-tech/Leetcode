/*
Pattern: Two Pointers (Length Alignment)

Approach:
- Traverse both linked lists to calculate
  their lengths.
- Move the pointer of the longer list forward
  until both lists have the same remaining length.
- Traverse both lists together.
- If the two pointers point to the same node,
  return that node as the intersection.
- If both pointers reach the end without meeting,
  return nullptr.

Key Insight:
- After aligning the remaining lengths,
  both pointers have the same distance to the end.
- If an intersection exists, they will meet at
  the first common node.

Complexity:
- Time: O(m + n)
    - Each list is traversed at most twice.
- Space: O(1)
    - Only a few pointers and variables are used.

Takeaway:
- For linked list intersection problems,
  think → Two Pointers + Length Alignment.
- Align the remaining lengths before traversing
  both lists together.
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        ListNode* tmp = headA;
        while (tmp)
        {
            tmp = tmp->next;
            sizeA++;
        }
        tmp = headB;
        while (tmp)
        {
            tmp = tmp->next;
            sizeB++;
        }
        while (sizeA > sizeB)
        {
            headA = headA->next;
            sizeA--;
        }
        while (sizeA < sizeB)
        {
            headB = headB->next;
            sizeB--;
        }
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
