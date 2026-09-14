/*
LeetCode 133 — Clone Graph

Pattern: Graph + DFS (Depth-First Search) + Hash Map

Approach:
- Use DFS to traverse every Node.
- Use a Hash Map to store:
    `Original Node → Cloned Node`
- When visiting a Node:
    → If it has already been cloned
      → return the existing Clone.
    → If it has not been cloned
      → create a new Node.
      → store it in the map.
      → DFS all its neighbors.
      → connect the cloned neighbors to the Clone.
- Store the Clone before DFS its neighbors to prevent cycles.

Key Insight:
- Graph can contain cycles.
- The Hash Map prevents infinite recursion.
- `Original Node → Cloned Node`
  allows us to reuse the same Clone Node.
- Already cloned → use existing Clone.
- Not cloned → Create → Store → DFS neighbors.

Example:
    1 → 2
    ↑   ↓
    └───┘

    Original:
    1, 2

    Clone:
    1', 2'

    Map:
    1 → 1'
    2 → 2'

Takeaway:
- 133 → Graph + DFS + Hash Map.
- Map stores `Original → Clone`.
- Not cloned → Create → Map → DFS.
- Already cloned → Return existing Clone.
- Map is essential for handling cycles.
- `V` = Vertices = Node 数量.
- `E` = Edges = Connection 数量.

Complexity:
- Time: O(V + E)
    - Visit each Node (V).
    - Check each connection/Edge (E).
- Space: O(V)
    - Hash Map stores each Node and its Clone.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        if (mp.find(node) != mp.end())
            return mp[node];
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for (Node* neighbor : node->neighbors)
            copy->neighbors.push_back(cloneGraph(neighbor));
        return copy;
    }
};
