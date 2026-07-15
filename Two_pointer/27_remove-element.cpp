/*
Pattern: Two Pointers (Fast & Slow)
Idea:
- Traverse the array once using two pointers:
    - fast scans every element.
    - slow keeps track of the next position to place a valid element.
- Create an integer count = 0 to record how many elements equal val.
- For each element:
    - If nums[fast] == val:
        Increase count.
    - Otherwise:
        Copy nums[fast] to nums[slow].
        Move slow forward.
- After traversal:
    - The first slow elements are the remaining valid elements.
    - Return nums.size() - count (equivalent to returning slow).
Optimal Approach:
- Use fast to examine every element.
- Use slow to overwrite elements that should be kept.
- Count how many elements are removed.
- The remaining elements are compacted at the beginning of nums without using extra space.

Key Insight:
- fast reads every element exactly once.
- slow always points to the next insertion position.
- count records the number of removed elements.
- Since:
    kept elements = total elements - removed elements,
    nums.size() - count is always equal to slow after the loop.
- The values after the returned length do not matter.

Key STL:
vector<int>

Time: O(n)
- Each element is visited exactly once.
Space: O(1)
- No extra array is used.

Mistakes:
- Forgetting to increment slow after copying a valid element.
- Returning nums.size() instead of the new length.
- Using an extra vector unnecessarily.
- count is optional; returning slow is simpler because slow already equals the number of kept elements.

Takeaway:
- For filtering elements in-place:
    Think → Fast & Slow Pointers.
- slow represents the number of valid elements.
- count can also be used to calculate the answer:
    new length = nums.size() - count.
- In practice, returning slow is cleaner because it already stores the new length.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
