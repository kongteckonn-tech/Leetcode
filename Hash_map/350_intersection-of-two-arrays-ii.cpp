/*
Pattern: Hash Map / Two Pointers (Best, when sorting is allowed)
Idea:
      First idea:
      - Use an unordered_map to count frequency of each number in nums1.
      - Traverse nums2, check if count > 0 in map, if so add to result and decrement.
      - O(n + m) time, but O(min(n,m)) extra space for the map.

      Best solution:
      - Sort both nums1 and nums2.
      - Use two pointers, index1 starting at nums1, index2 starting at nums2.
      - If nums1[index1] < nums2[index2], index1 doesn't have a match yet, move index1++.
      - If nums1[index1] > nums2[index2], move index2++.
      - If equal, it's a match: push to result, move both pointers forward.
      - This naturally handles duplicates correctly since matched elements
        are consumed (pointer advances) instead of reused.
Key STL: std::sort, vector
Time:
      - Hash Map: O(n + m)
      - Two Pointers: O(n log n + m log m) due to sorting (main cost); the merge itself is O(n + m)
Space:
      - Hash Map: O(min(n, m))
      - Two Pointers: O(1) extra space (sorting nums1/nums2 in place; ignoring sort's internal stack space)
Mistakes:
      - None major here — logic is correct and mirrors the standard merge-style
        intersection used for sorted arrays.
Takeaway:
      - Two Pointers avoids extra space compared to Hash Map, at the cost of
        needing the arrays sorted (or already sorted as input).
      - This is the preferred approach for the LeetCode follow-up where nums1
        is already sorted, or memory is constrained.
      - Sorting mutates the original arrays — fine here since order isn't
        required in the output, but worth noting if input order must be preserved.
*/
#include<algorithm>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> mp;
    //     vector<int> ret;
    //     for (int it : nums1)
    //         mp[it]++;
    //     for (int it : nums2)
    //     {
    //         if (mp[it] != 0)
    //         {
    //             ret.push_back(it);
    //             mp[it]--;
    //         }
    //     }
    //     return ret;
        int index1 = 0, index2 = 0;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> ret;
        while (index1 < nums1.size() && index2 < nums2.size())
        {
            if(nums1[index1] > nums2[index2])
                index2++;
            else if (nums1[index1] < nums2[index2])
                index1++;
            else
            {
                ret.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return ret;
    }
};
