/*
Pattern: Linked List (Dummy Node + Two Pointers)

Approach:
- Create a dummy node before `head` to handle deletion of
  the first node easily.
- Use `tmp` to track the previous node and `next` to traverse
  the current node.
- If `next->val` equals `val`, remove the current node by
  connecting `tmp->next` to `next->next`.
- If the value is different, move `tmp` to the next node.
- Always move `next` to the next node after checking.
- Return `dummy->next` as the new head.

Key Insight:
- `tmp` stays at the previous valid node when a node is deleted.
- The dummy node makes it possible to remove the original
  head without special handling.

Complexity:
- Time: O(n)
    - Traverse the linked list once.
- Space: O(1)
    - Only a few pointers are used.

Takeaway:
- Linked List + Remove Nodes
  → Use a Dummy Node.
- `next` checks the current node.
- `tmp` points to the previous node.
- Same value → skip the node.
- Different value → move `tmp`.
*/ 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp = dummy;
        ListNode* next = head;
        while (next && tmp)
        {
            if (next->val == val)
            {
                tmp->next = next->next;
            }
            else tmp = tmp->next;
            next = next->next;
        }
        return dummy->next;
    }
};
