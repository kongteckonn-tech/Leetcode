/*
Pattern: Grid + DFS (Depth-First Search)

Approach:
- Traverse every cell in the grid.
- If `grid[row][col] == 0`
  → skip it.
- If `grid[row][col] == 1`
  → found an island
  → use DFS to calculate its area.
- Change every visited `1` to `0` to mark it as visited.
- DFS checks 4 directions:
    → Up
    → Down
    → Left
    → Right
- The area of an island is:
    `1 + up + down + left + right`
- Update `maxArea` with the largest island area.

Key Insight:
- Each connected group of `1`s is one island.
- Every `1` contributes `1` to the area.
- Changing `1 → 0` prevents counting the same cell again.
- `maxArea` keeps track of the largest island.

Complexity:
- Time: O(m × n)
    - Each cell is visited at most once.
- Space: O(m × n)
    - Worst case DFS recursion stack.

Takeaway:
- 200 → Count number of islands.
- 695 → Find the largest island area.
- Find `1`
  → DFS
  → `1 → 0`
  → calculate area
  → update `maxArea`.
  */
class Solution {
private:
    int maxArea = INT_MIN;
    int islandArea(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 ||
            row >= grid.size() ||
            col < 0 || 
            col >= grid[0].size() ||
            grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        return 
            islandArea(grid, row - 1, col) +
            islandArea(grid, row + 1, col) +
            islandArea(grid, row, col - 1) +
            islandArea(grid, row, col + 1) + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[0].size(); col++)
                if (grid[row][col] != 0)
                    maxArea = std::max(maxArea, islandArea(grid, row, col));
        return maxArea == INT_MIN ? 0 : maxArea;
    }
};
