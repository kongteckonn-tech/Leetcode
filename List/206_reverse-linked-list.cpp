/*
Pattern: Two Pointers (Iterative Linked List Reversal)

Approach:
- Handle the edge case where the list is empty.
- Use `pre` to store the previous node.
- Use `cur` to traverse the list.
- Save `cur->next` before changing the link.
- Reverse the current node by pointing it to `pre`.
- Move both pointers forward.
- When traversal finishes, `cur` becomes the new head.

Key Insight:
- Reverse one link at a time while keeping track
  of the remaining list.
- Always save the next node before modifying pointers,
  otherwise the rest of the list will be lost.

Complexity:
- Time: O(n)
    - Each node is visited exactly once.
- Space: O(1)
    - Only a few pointers are used.

Takeaway:
- For reversing a linked list,
  think → Two Pointers + Pointer Reversal.
- Save the next node before reversing the current link.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur->next != NULL)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        cur->next = pre;
        return cur;
    }
};
