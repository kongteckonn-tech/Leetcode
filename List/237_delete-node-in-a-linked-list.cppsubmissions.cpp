/*
Pattern: Linked List (Value Copying)

Approach:
- The node to be deleted is given directly, but we do not
  have access to the previous node.
- Copy the value of the next node into the current node.
- Continue moving forward and copy each next node's value
  into the current node.
- When reaching the second-last node, remove the last node
  by setting `node->next` to `NULL`.
- This makes the original node appear to be deleted.

Key Insight:
- Since we cannot access the previous node, we cannot
  directly remove the given node.
- Instead, shift all following values one position forward.
- Finally remove the last node.
- The problem guarantees that the given node is not the
  last node.

Complexity:
- Time: O(n)
    - In the worst case, values are shifted through the
      remaining nodes.
- Space: O(1)
    - Only the given pointer is used.

Takeaway:
- Cannot access previous node
  → Copy the next node's value forward.
- Move through the list until the last node.
- Remove the final node to complete the deletion.
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
    void deleteNode(ListNode* node) {
        while (node)
        {
            node->val = node->next->val;
            if (node->next->next == NULL)
            {
                node->next = NULL;
                break;
            }
            node = node->next;
        }
    }
};
