/*
Pattern: Linked List (Traversal + New List)

Approach:
- Create a dummy node `ret` to represent the beginning
  of the new linked list.
- Use `tmp` to point to the last node of the new list.
- Traverse the original linked list using `head`.
- Compare `head->val` with `tmp->val`.
- If the value is different, create a new node and
  attach it to the new list.
- If the value is the same, skip it because it is a duplicate.
- Move `head` to the next node and continue.
- Return `ret->next` to skip the dummy node.

Key Insight:
- The linked list is sorted, so duplicate values are
  next to each other.
- Only add a node when its value is different from the
  last value added to the new list.
- The dummy node makes it easier to build the new list.

Complexity:
- Time: O(n)
    - Traverse the original linked list once.
- Space: O(n)
    - Create a new linked list containing the unique values.

Takeaway:
- Sorted Linked List + Remove Duplicates
  → Traverse the list and build a new list.
- Compare the current value with the last value added.
- Same → skip.
- Different → create and add a new node.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode(-101);
        ListNode* tmp;
        tmp = ret;
        while (head != NULL)
        {
            if (head->val != tmp->val)
            {
                ListNode* create = new ListNode(head->val);
                tmp->next = create;
                tmp = tmp->next;
            }
            head = head->next;
        }
        return ret->next;
    }
};
