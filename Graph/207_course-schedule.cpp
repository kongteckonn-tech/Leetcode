/*
LeetCode 207 — Course Schedule

Pattern: Graph + DFS + Cycle Detection

Approach:
- Build a directed Graph:
    `prerequisite → course`
- Use `state` to track each Course:
    0 → Not Visited
    1 → Currently Visiting
    2 → Completely Visited
- Use DFS to check every Course.
- When visiting a Course:
    - state == 1 → Cycle found → return false.
    - state == 2 → Already checked → return true.
    - Set state = 1.
    - DFS all neighboring Courses.
    - After finishing → set state = 2.
- If any DFS finds a Cycle:
    → return false.
- If all Courses are checked without a Cycle:
    → return true.

Key Insight:
- The problem is asking whether all Courses can be completed.
- A Cycle means Courses depend on each other forever.
- Example:
    `0 → 1 → 2 → 0`
    → Cycle exists
    → Cannot finish all Courses.
- `state == 1` means the Course is in the current DFS path.
- Reaching a `state == 1` Course means we returned to the current path
  → Cycle exists.
- `state == 2` means the Course has already been completely checked.

Example:
    prerequisites = [[1,0],[0,1]]

    Graph:
        0 → 1
        ↑   ↓
        └───┘

    DFS:
        0 → 1 → 0

    `0` is already `state == 1`
    → Cycle found
    → return false

Takeaway:
- 207 → Graph + DFS + Cycle Detection.
- `state == 0` → Not Visited.
- `state == 1` → Currently Visiting.
- `state == 2` → Completely Visited.
- `state == 1` during DFS → Cycle.
- No Cycle → Can finish all Courses.

Complexity:
- Time: O(V + E)
    - Visit each Course (V).
    - Check each connection (E).
- Space: O(V + E)
    - Graph: O(V + E).
    - State: O(V).
*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> state;
    bool dfs(int course)
    {
        // 正在当前 DFS 路径中
        if (state[course] == 1)
            return false;
        // 已经检查完成，没有 Cycle
        if (state[course] == 2)
            return true;
        // 标记为正在访问
        state[course] = 1;
        // 检查所有下一个课程
        for (int next : graph[course])
        {
            if (!dfs(next))
                return false;
        }
        // 当前 Course 检查完成
        state[course] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        graph.resize(numCourses);
        state.resize(numCourses, 0);
        // 建立 Graph
        for (auto& prerequisite : prerequisites)
        {
            int course = prerequisite[0];
            int pre = prerequisite[1];

            graph[pre].push_back(course);
        }
        // 从每一个 Course 开始检查
        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course))
                return false;
        }
        return true;
    }
};
