/*
Pattern: Grid + DFS (Depth-First Search)

Approach:
- Store the original color:
    `oldColor = image[sr][sc]`
- Start DFS from `(sr, sc)`.
- If the position is out of bounds → return.
- If the current color is not `oldColor` → return.
- Change the current cell to `newColor`.
- Recursively DFS in 4 directions:
    → Up
    → Down
    → Left
    → Right
- If `oldColor == newColor`, return immediately.

Key Insight:
- Only change cells that have the same color as the starting cell.
- Changing the cell to `newColor` also marks it as visited.
- Diagonal cells are not connected.

Example:
    1 1 0
    1 0 0

Start at `1`, new color = `2`

    2 2 0
    2 0 0

Takeaway:
- 733 → Grid + DFS.
- Record `oldColor`.
- `oldColor` → change to `newColor`.
- Different color → stop.
- DFS → Up, Down, Left, Right.
- `oldColor == newColor` → return directly.

Complexity:
- Time: O(m × n)
- Space: O(m × n)
*/
class Solution {
private: 
    int num = INT_MIN;
    void fill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (sr < 0 || 
            sr >= image.size() || 
            sc < 0 || 
            sc >= image[0].size() ||
            image[sr][sc] != num)
            return;
        image[sr][sc] = color;
        fill(image, sr - 1, sc, color);
        fill(image, sr + 1, sc, color);
        fill(image, sr, sc - 1, color);
        fill(image, sr, sc + 1, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        num = image[sr][sc];
        if (num == color)
            return image;
        fill(image, sr, sc, color);
        return image;
    }
};
