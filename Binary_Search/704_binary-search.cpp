/*
Pattern: Binary Search

Approach:
- Use two pointers:
    `left = 0`
    `right = nums.size() - 1`
- Find the middle index:
    `mid = left + (right - left) / 2`
- Compare `nums[mid]` with `target`.
- If equal → return `mid`.
- If `nums[mid] < target` → search the right half.
- If `nums[mid] > target` → search the left half.
- If the loop ends → target does not exist, return `-1`.

Key Insight:
- The array is sorted.
- Each comparison eliminates half of the search space.

Takeaway:
- Binary Search:
  → Sorted array.
  → Check middle.
  → Smaller → go Left.
  → Larger → go Right.
  → Equal → Found.

Complexity:
- Time: O(log n)
- Space: O(1)
  */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int i = 0;
        // while (i < nums.size())
        // {
        //     if (nums[i] == target)
        //         return i;
        //     i++;
        // }
        // return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};
