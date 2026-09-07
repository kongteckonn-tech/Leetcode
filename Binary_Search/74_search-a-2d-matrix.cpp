/*
Pattern: Binary Search

Approach:
- First Binary Search:
    → Find the row that may contain `target`.
- Compare `target` with the first and last value of the row.

    target > last value
    → target is in a lower row
    → left = mid + 1

    target < first value
    → target is in an upper row
    → right = mid - 1

    otherwise
    → target may be inside this row
    → stop searching for the row.

- Second Binary Search:
    → Search for `target` inside the selected row.
- If found → return `true`.
- Otherwise → return `false`.

Key Insight:
- The matrix has two levels of sorted order:
    1. Rows are ordered.
    2. Each row is sorted.
- Therefore:
    → Binary Search for Row
    → Binary Search for Column.

Complexity:
- Time: O(log m + log n)
    - `m` = number of rows.
    - `n` = number of columns.
- Space: O(1)

Takeaway:
- 2D Matrix Binary Search
  → First find the correct row.
  → Then search inside that row.
- `target > row's last`
  → go down.
- `target < row's first`
  → go up.
- Otherwise
  → search this row.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (target > matrix[mid][matrix[mid].size() - 1])
                left = mid + 1;
            else if (target < matrix[mid][0])
                right = mid - 1;
            else break;
        }
        int inLeft = 0, inRight = matrix[0].size() - 1;
        while (inLeft <= inRight && left <= right)
        {
            int inMid = (inLeft + inRight) / 2;
            if (matrix[mid][inMid] == target)
                return true;
            if (matrix[mid][inMid] < target)
                inLeft = inMid + 1;
            else inRight = inMid - 1;
        }
        return false;
    }
};
