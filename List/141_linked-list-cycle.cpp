/*
Pattern: Fast & Slow Pointers (Floyd's Cycle Detection)

Approach:
- Initialize both `slow` and `fast` at the head.
- Move `slow` one step at a time.
- Move `fast` two steps at a time.
- If `slow` and `fast` meet, a cycle exists.
- If `fast` or `fast->next` becomes `nullptr`,
  the list has no cycle.

Key Insight:
- If a cycle exists, the faster pointer will
  eventually catch up with the slower pointer.
- If there is no cycle, the fast pointer will
  reach the end of the list first.

Complexity:
- Time: O(n)
    - Each node is visited at most a constant number of times.
- Space: O(1)
    - Only two pointers are used.

Takeaway:
- For detecting a cycle in a linked list,
  think → Fast & Slow Pointers.
- Use `while (fast && fast->next)` to safely
  move the fast pointer two steps each iteration.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
