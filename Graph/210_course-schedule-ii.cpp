/*
LeetCode 210 — Course Schedule II

Pattern: Graph + DFS + Cycle Detection + Topological Sort

Approach:
- Build a directed Graph:
    `prerequisite → course`
- Use `state` to detect Cycle:
    0 → Not Visited
    1 → Currently Visiting
    2 → Completely Visited
- `isCycle()`:
    - state == 1 → Cycle found.
    - state == 2 → Already checked.
    - DFS all neighbors.
    - After finishing → state = 2.
- If a Cycle exists:
    → return `{}`.
- Reset `state` to 0.
- Use `element()` to perform DFS Topological Sort.
- After visiting all neighbors:
    → `push_back(node)`
- Reverse `ret` to get the correct Course Order.
- Start DFS from every unvisited Course to handle disconnected Graphs.

Key Insight:
- A Course must be completed after all its prerequisites.
- DFS visits all connected Courses first.
- Push the current Course only after all its neighbors are visited.
- This creates the order in reverse, so reverse `ret` at the end.
- `state == 1` means we returned to the current DFS path:
    → Cycle exists.

Example:
    prerequisites = [[1,0],[2,0],[3,1],[3,2]]

    Graph:
        0 → 1 → 3
        ↓       ↑
        2 ──────┘

    DFS result:
        3 → 1 → 2 → 0

    After reverse:
        0 → 2 → 1 → 3

Takeaway:
- 210 → Graph + DFS + Cycle Detection + Topological Sort.
- `isCycle()` checks whether the Graph has a Cycle.
- `element()` creates the Topological Order.
- Push the Node after DFS → Postorder.
- Reverse `ret` at the end.
- Must DFS every unvisited Course to handle disconnected Graphs.

Complexity:
- Time: O(V + E)
    - Visit each Course (V).
    - Check each connection (E).
- Space: O(V + E)
    - Graph: O(V + E).
    - State: O(V).
    - Result: O(V).
*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> state;
    vector<int> ret;
    bool isCycle(int course)
    {
        if (state[course] == 1)
            return true;
        if (state[course] == 2)
            return false;
        state[course] = 1;
        for (int next : graph[course])
            if (isCycle(next))
                return true;
        state[course] = 2;
        return false;
    }
    void element(int node)
    {
        state[node] = 1;
        for (int next : graph[node])
        {
            if (state[next] == 0)
                element(next);
        }
        ret.push_back(node);
        state[node] = 2;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.resize(numCourses, 0);
        for (auto i : prerequisites)
        {
            int index = i[1];
            int node = i[0];
            graph[index].push_back(node);
        }
        for (int course = 0; course < numCourses; course++)
            if (isCycle(course))
                return {};
        state.assign(numCourses, 0);
        for (int course = 0; course < numCourses; course++)
        {
            if (state[course] == 0)
                element(course);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
