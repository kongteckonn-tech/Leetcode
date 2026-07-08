/*
Pattern: Two Pointers (Fast & Slow Pointer)

Idea:
- Since the array is already sorted, duplicate elements are always next to each other.
- My idea was to use two pointers:
    - fast scans every element.
    - slow points to the last unique element.
- Whenever fast finds a new value different from nums[slow]:
    - Move slow forward.
    - Copy the new unique value to nums[slow].
- After the traversal, the first (slow + 1) elements are all unique.

Key Insight:
- A sorted array groups duplicate values together.
- We only need to compare the current element with the last unique element.
- The array can be modified in-place without using extra memory.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- No mistakes

Takeaway:
- When the input array is sorted, two pointers are often the best solution.
- Fast pointer scans the array, while slow pointer keeps track of the valid portion.
- Instead of deleting duplicates, overwrite them with the next unique element.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0, slow = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow])
                nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};
