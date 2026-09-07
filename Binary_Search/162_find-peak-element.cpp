/*
Pattern: Binary Search

Approach:
- Use `left` and `right` to represent the search range.
- While `left < right`, calculate `mid`.
- Compare `nums[mid]` with `nums[mid + 1]`.

- If:
    `nums[mid] < nums[mid + 1]`
  → We are going uphill.
  → A peak must exist on the right.
  → `left = mid + 1`

- Otherwise:
    `nums[mid] > nums[mid + 1]`
  → We are going downhill.
  → `mid` itself could be a peak.
  → A peak exists at `mid` or on the left.
  → `right = mid`

- When `left == right`:
  → Only one position remains.
  → That position is a peak.
  → Return `right`.

Key Insight:
- Don't search for the biggest value.
- Use the slope between `mid` and `mid + 1`.
- Going up → Peak is on the right.
- Going down → Peak is on the left or `mid`.

Complexity:
- Time: O(log n)
- Space: O(1)

Takeaway:
- `nums[mid] < nums[mid + 1]`
  → Up → go right.
- `nums[mid] > nums[mid + 1]`
  → Down → go left / keep mid.
- `left == right`
  → Peak found.

Pattern:
- 704 → Basic Binary Search.
- 33 → Rotated Array + Binary Search.
- 153 → Rotated Array + Binary Search + Find Minimum.
- 162 → Binary Search using the slope.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};
