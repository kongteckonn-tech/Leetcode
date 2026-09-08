/*
Pattern: Binary Search

Approach:
- Find the largest integer `mid` such that:
    `mid² <= x`
- Use Binary Search from `1` to `x`.
- Use `x / mid` instead of `mid * mid` to avoid integer overflow.

- `mid < x / mid`
    → mid² < x
    → mid is too small
    → save mid
    → search right.

- `mid > x / mid`
    → mid² > x
    → mid is too large
    → search left.

- Otherwise:
    → exact square root found.

Key Insight:
- We are looking for the largest `mid` satisfying:
    `mid² <= x`
- This is a Binary Search for the boundary.

Complexity:
- Time: O(log x)
- Space: O(1)

Takeaway:
- 69 = Binary Search + Find Maximum.
- `mid² < x` → go right.
- `mid² > x` → go left.
- `mid² == x` → found.
- `x / mid` prevents overflow.
  */
class Solution {
public:
    int mySqrt(int x) {
        int ans = -1;
        int left = 1, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid < x / mid)
            {
                ans = std::max(ans, mid);
                left = mid + 1;
            }
            else if (mid > x / mid)
                right = mid - 1;
            else 
            {
                ans = std::max(ans, mid);
                break;
            }
        }
        return (ans == -1) ? 0 : ans;
    }
};
