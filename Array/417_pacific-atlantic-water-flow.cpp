/*
LeetCode 417 — Pacific Atlantic Water Flow

Pattern: Grid + DFS (Reverse Traversal)

Approach:
- Pacific Ocean touches:
    → Top
    → Left
- Atlantic Ocean touches:
    → Bottom
    → Right
- Instead of starting from every cell, start DFS from both oceans.
- Reverse the water flow:
    Real water: High → Low
    Reverse DFS: Low → High
- For Reverse DFS:
    - If the next cell is lower than the current cell
      → cannot move there.
    - Otherwise
      → continue DFS.
- Use two visited grids:
    `pacific` → cells that can reach Pacific.
    `atlantic` → cells that can reach Atlantic.
- If a cell is visited by both:
    → add it to the result.
- DFS checks 4 directions:
    → Up
    → Down
    → Left
    → Right

Key Insight:
- Real water flows from higher/equal height to lower/equal height.
- We reverse the search so that we can start from the oceans.
- Reverse DFS can move:
    `next height >= current height`
- Pacific starts from:
    `Top + Left`
- Atlantic starts from:
    `Bottom + Right`
- A cell can reach both oceans if:
    `pacific[row][col] && atlantic[row][col]`

Example:
    1 2 2 3 5
    3 2 3 4 4
    2 4 5 3 1
    6 7 1 4 5
    5 1 1 2 4

For `[2,2] = 5`:

Pacific:
    5 → 3 → 2 → 2 → 1
    [2,2] → [1,2] → [0,2] → [0,1] → [0,0]

Atlantic:
    5 → 1 → 1
    [2,2] → [3,2] → [4,2]

Therefore `[2,2]` can reach both oceans.

Takeaway:
- 417 → Grid + DFS + Reverse Traversal.
- Pacific → Top + Left.
- Atlantic → Bottom + Right.
- Real water → High → Low.
- Reverse DFS → Low → High.
- Use two visited grids.
- Both visited → Add to result.

Complexity:
- Time: O(m × n)
- Space: O(m × n)
*/
class Solution {
private:
    int m, n;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int row, int col)
    {
        visited[row][col] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            // 越界
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // 已经访问
            if (visited[nr][nc])
                continue;

            // Reverse DFS：只能走到更高或一样高的地方
            if (heights[nr][nc] < heights[row][col])
                continue;

            dfs(heights, visited, nr, nc);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific：上边 + 左边
        for (int col = 0; col < n; col++)
        {
            dfs(heights, pacific, 0, col);
        }

        for (int row = 0; row < m; row++)
        {
            dfs(heights, pacific, row, 0);
        }

        // Atlantic：下边 + 右边
        for (int col = 0; col < n; col++)
        {
            dfs(heights, atlantic, m - 1, col);
        }

        for (int row = 0; row < m; row++)
        {
            dfs(heights, atlantic, row, n - 1);
        }

        // 两个 Ocean 都可以到达
        vector<vector<int>> result;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (pacific[row][col] && atlantic[row][col])
                {
                    result.push_back({row, col});
                }
            }
        }

        return result;
    }
};
