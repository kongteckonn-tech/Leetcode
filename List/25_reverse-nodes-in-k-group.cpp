/*
Pattern: Linked List (Group Reversal)

Approach:
- Use a dummy node before `head` to simplify reconnecting
  each reversed group.
- Use `tmp` to point to the node before the current group.
- Use `end` to locate the next group of `k` nodes.
- For each group, use `slow` and `fast` to reverse the
  nodes by changing their `next` pointers.
- Move each `fast` node to the front of the current group,
  gradually reversing the group.
- After reversing, update `end` and `tmp` to prepare for
  the next group.
- Check whether the remaining nodes contain a complete
  group of `k` nodes before continuing.
- Return `dummy->next`.

Key Insight:
- Reverse the nodes directly by manipulating `next` pointers
  instead of creating new nodes.
- `tmp` keeps track of the node before the current group.
- `slow` and `fast` are used to move and reconnect nodes
  during the reversal.
- Only reverse a group when there are enough nodes.
- If the remaining nodes are fewer than `k`, they should
  remain in their original order.

Complexity:
- Time: O(n)
    - Each node is processed a constant number of times.
- Space: O(1)
    - Only pointers are used.

Takeaway:
- Reverse Linked List in Groups of `k`
  → Find a complete group → Reverse the group
  → Connect it back → Move to the next group.
- The key is controlling the `next` pointers carefully.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* tmp = dummy;
        ListNode* end = head;
        while (end)
        {
            ListNode* slow = end;
            ListNode* fast = end->next;
            for (int i = 1; i < k; i++)
            {
                slow->next = fast->next;
                fast->next = tmp->next;
                tmp->next = fast;
                fast = slow->next;
            }
            end = tmp->next;
            tmp = slow;
            for (int i = 0; end && i < k; i++)
                end = end->next;
            ListNode* check = end;
            for (int i = 0; i < k; i++)
            {
                if (!check)
                    end = NULL;
                else check = check->next;
            }
        }
        return dummy->next;
    }
};
