/*
Pattern: Sorting / Two Pointers (Merge from Back)
Idea:
- My first idea was to use the merge process from merge sort.
- Create an extra vector and use two pointers:
    - One pointer for nums1.
    - One pointer for nums2.
- Compare both values and put the smaller value into the result array.
- This approach works, but it requires extra O(m+n) space.
Optimal Approach:
- Since nums1 already has extra space at the end, merge the arrays in-place.
- Use three pointers:
    - i points to the last valid element in nums1.
    - j points to the last element in nums2.
    - k points to the last position of nums1.
- Compare nums1[i] and nums2[j]:
    - If nums1[i] is larger:
        Put nums1[i] at nums1[k].
        Move i and k backward.
    - Otherwise:
        Put nums2[j] at nums1[k].
        Move j and k backward.
- After the first loop:
    - If nums2 still has remaining elements, copy them into nums1.
    - No need to copy remaining nums1 elements because they are already in the correct position.
Key Insight:
- Merging from the back prevents overwriting the original values in nums1.
- The largest value should be placed at the end first.
- Using three pointers allows the merge operation to be done in-place.
- The reason we only need to check nums2 after merging:
    - nums1 elements are already inside nums1.
    - If nums1 has remaining elements, they are already sorted.
Key STL:
vector<int>

Time: O(m+n)
- Each element from nums1 and nums2 is processed at most once.
Space: O(1)
- No extra vector is used.
- The merge is done directly inside nums1.

Mistakes:
- Initially used an extra vector to store the merged result.
- Merging from the front can overwrite the remaining values in nums1.
- The first while loop should not require k >= 0 because k will always be valid when i and j are valid.
- Need an additional while loop for remaining nums2 elements.
- No need to handle remaining nums1 elements because they are already in the correct position.

Takeaway:
- For merging sorted arrays with extra space available:
    Think → Two Pointers from the Back.
- Merge Sort's merge idea can be optimized from O(n) space to O(1) space.
- When modifying an array in-place, always consider whether filling from the end avoids overwriting data.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     if (nums1.empty())
    //     {
    //         nums1 = nums2;
    //         return;
    //     }
    //     if (nums2.empty())
    //         return;
    //     vector<int> ret;
    //     int i = 0, j = 0;
    //     while (i < m && j < n)
    //     {
    //         if (nums1[i] < nums2[j])
    //         {
    //             ret.push_back(nums1[i++]);
    //         }
    //         else ret.push_back(nums2[j++]);
    //     }
    //     while (i < m)
    //         ret.push_back(nums1[i++]);
    //     while (j < n)
    //         ret.push_back(nums2[j++]);
    //     nums1 = ret;
    // }
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (k >= 0 && i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else 
                nums1[k--] = nums2[j--];
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
