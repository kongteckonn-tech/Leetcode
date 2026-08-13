/*
Pattern: Linked List (Dummy Node + Pair Swapping)

Approach:
- Create a dummy node before `head` to make swapping the
  first pair easier.
- Use `prev` to point to the node before the pair.
- Use `first` and `second` to represent the two nodes
  that need to be swapped.
- Swap the two nodes by changing their `next` pointers:
    1. Connect `first` to the node after `second`.
    2. Connect `second` to `first`.
    3. Connect `prev` to `second`.
- After swapping, move `prev` to `first` and continue
  with the next pair.
- If fewer than two nodes remain, stop.
- Return `dummy->next`.

Key Insight:
- Swap the nodes by changing pointers, not their values.
- For every pair:

    prev → first → second → next

  becomes:

    prev → second → first → next

- `prev` must stay before the pair so that the previous
  part of the linked list can connect to the new first node.

Complexity:
- Time: O(n)
    - Each node is processed once.
- Space: O(1)
    - Only a few pointers are used.

Takeaway:
- Swap Linked List Nodes in Pairs
  → Dummy Node + Three Pointer Changes.
- `first` = first node of the pair.
- `second` = second node of the pair.
- `prev` = node before the pair.
- Swap pointers → move `prev` to the next pair.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        return dummy->next;
    }
};
