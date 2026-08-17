/*
Pattern: Linked List (Copy with Random Pointer)

Approach:
- Use the original linked list to store the copied nodes,
  avoiding the need for a HashMap.
- First, create a copy of every node and insert it directly
  after the original node.

  Original:
    A → B → C

  After inserting copies:
    A → A' → B → B' → C → C'

- Traverse the interleaved list again and set the `random`
  pointer of each copied node.
- Since every original node is followed by its copy,
  `tmp->random->next` can directly find the copied node
  corresponding to `tmp->random`.
- Finally, separate the original nodes and copied nodes
  into two independent linked lists.
- Return the head of the copied list.

Key Insight:
- Insert each copied node immediately after its original
  node, so we can find the corresponding copied node
  without using a HashMap.
- If:
    A.random → C
  then:
    A'.random → C'
  because:
    C.next → C'
- The algorithm works in three stages:
    1. Create and insert copied nodes.
    2. Set copied nodes' random pointers.
    3. Separate the original and copied lists.

Complexity:
- Time: O(n)
    - Traverse the list a constant number of times.
- Space: O(1) extra space
    - No HashMap or additional data structure is used.
    - The copied nodes themselves require O(n) memory.

Takeaway:
- Copy Linked List + Random Pointer
  → Interleave → Set Random → Separate.
- `original->next` points to its copy.
- `original->random->next` finds the copy of the random node.
- This allows the problem to be solved without a HashMap.
*/
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (!head) return head;
            Node* ret = head;
            Node* tmp = ret;
            while (head)
            {
                Node* node = new Node(head->val);
                Node* next = head->next;
                node->next = head->next;
                head->next = node;
                head = next;
            }
            tmp = ret;
            while (tmp != NULL && tmp->next != NULL)
            {
                Node* next = tmp->next;
                if (tmp->random != NULL)
                    next->random = tmp->random->next;
                else
                    next->random = NULL;
                tmp = next->next;
            }
            tmp = ret;
            Node* dummy = new Node(0);
            ret = dummy;
            while (tmp != NULL)
            {
                dummy->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next = tmp->next->next;
                tmp = tmp->next;
                dummy = dummy->next;
            }
            dummy->next = NULL;
            return ret->next;
        }
};
