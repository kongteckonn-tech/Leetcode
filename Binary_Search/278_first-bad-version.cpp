/*
Pattern: Binary Search + Find First

Approach:
- Versions are ordered:
    Good → Good → Good → Bad → Bad → Bad
- Use Binary Search to find the first bad version.
- Check `isBadVersion(mid)`.

- If `mid` is bad:
    → `mid` could be the first bad version.
    → Keep `mid`.
    → Search left.
    → `right = mid`

- If `mid` is good:
    → `mid` cannot be the answer.
    → Search right.
    → `left = mid + 1`

- When `left == right`:
    → Only one version remains.
    → It is the first bad version.
    → Return `left`.

Key Insight:
- This is the same idea as LeetCode 34's "Find First".
- When we find a possible answer, DON'T remove it.
- Bad → `right = mid`
- Good → `left = mid + 1`

Complexity:
- Time: O(log n)
- Space: O(1)

Takeaway:
- 34 First:
    `target found → right = mid - 1`
- 278 First:
    `bad found → right = mid`

Why different?
- In 34, `mid` is already saved as the answer, so we can remove it.
- In 278, `mid` may still be the first bad version, so we must keep it.

Pattern:
- Binary Search
- Find First
- Boundary Search
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
