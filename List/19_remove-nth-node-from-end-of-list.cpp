/*
Pattern: Two Pointers (Fast & Slow Pointer with Dummy Node)

Approach:
- Create a dummy node before `head` to simplify
  removing the first node case.
- Use `last` as the fast pointer and move it `n`
  steps ahead first.
- If `last` reaches `NULL`, the node to remove
  is the head node.
- Otherwise, move both `head` and `last` together
  until `last` reaches the end.
- Remove the target node by changing the previous
  node's `next` pointer.

Key Insight:
- The gap between the two pointers is always `n`
  nodes.
- When the fast pointer reaches the end,
  the slow pointer will be at the node before
  the target node.
- A dummy node avoids special handling when
  deleting the first node.

Complexity:
- Time: O(n)
    - The list is traversed once.
- Space: O(1)
    - Only a few pointers are used.

Takeaway:
- For removing the nth node from the end,
  think → Two Pointers + Dummy Node.
- Keep a fixed gap between fast and slow pointers
  to locate the target node efficiently.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lead = new ListNode();
        ListNode* last = head;
        lead->next = head;
        int tmp = n;
        while (last != NULL && tmp != 0)
        {
            last = last->next;
            tmp--;
        }
        if (last == NULL)
            lead->next = lead->next->next;
        else
        {
            while(last->next != NULL)
            {
                head = head->next;
                last = last->next;
            }
            head->next = head->next->next;
        }
        return lead->next;
    }
};
