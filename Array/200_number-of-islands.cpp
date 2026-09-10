/*
Pattern: Grid + DFS (Depth-First Search)

Approach:
- Traverse every cell in the grid.
- If the cell is `'0'` → skip it.
- If the cell is `'1'`:
    → found a new island
    → `island++`
    → use DFS to find the whole island.
- Change every connected `'1'` to `'0'` to mark it as visited.
- DFS checks 4 directions:
    → Up
    → Down
    → Left
    → Right
- Continue scanning the grid.

Key Insight:
- One connected group of `'1'` represents one island.
- When we find the first `'1'` of an island:
    → `island++`
    → DFS removes/marks the entire island as `'0'`.
- Therefore, the same island will never be counted twice.
- Only 4 directions are connected; diagonal is not connected.

Complexity:
- Time: O(m × n)
    - Each cell is visited at most once.
- Space: O(m × n)
    - Worst case DFS recursion stack.

Takeaway:
- Find `'1'`
  → `island++`
  → DFS
  → connected `'1'` → `'0'`
  → continue scanning.
- One island → count once.
- Grid → DFS/BFS + Mark Visited.
  */
class Solution {
private: 
    void removeIsland(vector<vector<char>>& ch, int row, int col)
    {
        if (row < 0 || row >= ch.size() || col < 0 || col >= ch[0].size() || ch[row][col] == '0')
            return;
        ch[row][col] = '0';
        removeIsland(ch, row - 1, col);
        removeIsland(ch, row + 1, col);
        removeIsland(ch, row, col - 1);
        removeIsland(ch, row, col + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == '0')
                    continue;
                island++;
                removeIsland(grid, row, col);
            }
        }
        return island;
    }
};
