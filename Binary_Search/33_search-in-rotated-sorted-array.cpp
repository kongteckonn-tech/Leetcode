/*
Pattern: Binary Search

Approach:
- Use `left`, `right`, and `mid` to perform Binary Search.
- First check if `nums[mid] == target`.
- Since the array is rotated, one side of `mid` must be normally sorted.
- Check which side is sorted:
    `nums[left] <= nums[mid]`
- If the left side is sorted:
    - Check whether `target` is inside the left-side range.
    - If yes → search left.
    - Otherwise → search right.
- If the left side is not sorted:
    - The right side is sorted.
    - Check whether `target` belongs to the right-side range.
    - If yes → search right.
    - Otherwise → search left.

Key Insight:
- Rotated Sorted Array
  → One side of `mid` is always sorted.
- Find the sorted side.
- Check whether `target` is inside that sorted range.
- Use this to eliminate half of the array.

Takeaway:
- 704 → Normal Binary Search.
- 33 → Binary Search + Find Sorted Side.
- Left sorted → check left range.
- Right sorted → check right range.
- Then move `left` or `right`.

Complexity:
- Time: O(log n)
- Space: O(1)
  */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
