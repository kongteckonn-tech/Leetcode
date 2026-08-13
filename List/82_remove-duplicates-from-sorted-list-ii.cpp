/*
Pattern: Linked List (Dummy Node + Two Pointers)

Approach:
- Create a dummy node before `head` to handle duplicates
  at the beginning of the list.
- Use `head` to traverse the list and `prev` to point to
  the last node that should be kept.
- If `head` and `head->next` have the same value, continue
  moving `head` until all nodes with that value are skipped.
- Connect `prev->next` to `head->next` to remove the entire
  group of duplicates.
- If there is no duplicate, move `prev` forward.
- Continue until the end of the list.
- Return `dummy->next`.

Key Insight:
- Because the linked list is sorted, duplicate values are
  always next to each other.
- When a duplicate is found, remove the entire group instead
  of keeping one copy.
- `prev` only moves when the current value is confirmed unique.

Complexity:
- Time: O(n)
    - Each node is visited at most once.
- Space: O(1)
    - Only pointers are used.

Takeaway:
- Sorted Linked List + Remove ALL Duplicates
  → Dummy Node + Two Pointers.
- Duplicate → skip the entire group.
- Unique → move `prev`.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* prev = dummy;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                    head = head->next;
                prev->next = head->next;
            }
            else prev = prev->next;
            head = head->next;
        }
        return dummy->next;
    }
};
