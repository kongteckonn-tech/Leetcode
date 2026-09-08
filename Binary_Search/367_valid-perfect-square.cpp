/*
Pattern: Binary Search

Approach:
- A perfect square means there is an integer `mid` such that:
    `mid × mid == num`
- Use Binary Search from `1` to `num`.
- Use `num / mid` instead of `mid * mid` to avoid integer overflow.

- If:
    `mid < num / mid`
  → `mid² < num`
  → mid is too small
  → search right.

- If:
    `mid > num / mid`
  → `mid² > num`
  → mid is too large
  → search left.

- Otherwise:
    `mid == num / mid`
  → possible perfect square
  → check `num % mid == 0`
  → if true, return `true`.

Key Insight:
- Integer division can cause false equality.
- Example:
    `5 / 2 == 2`
  but:
    `2 × 2 != 5`
- Therefore, when `mid == num / mid`,
  we must also check:
    `num % mid == 0`

- Unlike LeetCode 69, we don't need the closest/largest value.
- We only need to find an exact square:
    `mid² == num`.

Complexity:
- Time: O(log n)
- Space: O(1)

Takeaway:
- 69 → Find `floor(√x)`.
- 367 → Check whether `√num` is an integer.
- Both use Binary Search.
- `mid < num / mid` → go right.
- `mid > num / mid` → go left.
- Equal → check `%` to confirm perfect square.
  */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid < num / mid)
                left = mid + 1;
            else if (mid > num / mid)
                right = mid - 1;
            else 
            {
                if (num % mid == 0)
                    return true;
                else return false;
            }
        }
        return false;
    }
};
