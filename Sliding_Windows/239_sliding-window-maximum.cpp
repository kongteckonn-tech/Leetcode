/*
Pattern: Fixed Sliding Window

My Approach: Multiset
- Use `multiset<int, greater<int>>` to store all elements
  inside the current window.
- `greater<int>` keeps the elements in decreasing order,
  so `*sub.begin()` is always the maximum value.
- First insert the first `k` elements into the multiset.
- Move the window one position at a time:
  remove the element leaving from the left and insert
  the new element from the right.
- Record `*sub.begin()` as the maximum of each window.
- Use `multiset` instead of `set` because duplicate values
  are allowed in the window.

My Approach Complexity:
- Time: O(n log k)
    - Each insert and erase takes O(log k).
- Space: O(k)
    - The multiset stores at most `k` elements.

Optimal Approach: Monotonic Deque
- Use a deque to store indices instead of values.
- Keep the values in decreasing order.
- Remove smaller or equal values from the back because
  they can never become the maximum while the current
  element is in the window.
- Remove indices from the front when they leave the window.
- The front of the deque always represents the maximum
  value of the current window.

Key Insight:
- The window size is fixed at `k`.
- Multiset → easy way to maintain the maximum.
- Monotonic Deque → optimized way to maintain the maximum.
- `deque` stores indices because we need to know whether
  an element has left the window.

Optimal Complexity:
- Time: O(n)
    - Each index enters and leaves the deque at most once.
- Space: O(k)
    - The deque stores at most `k` indices.

Takeaway:
- Sliding Window Maximum
  → Fixed Sliding Window.
- Simple solution
  → Multiset.
- Optimal solution
  → Monotonic Deque.
*/
#include<set>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if (nums.size() < k)
        //     return {};
        // multiset<int, greater<int>> sub;
        // vector<int> ret;
        // int left = 0, right = 0;
        // while (right < k)
        //     sub.insert(nums[right++]);
        // ret.push_back(*sub.begin());
        // while (right < nums.size())
        // {
        //     if (right - left >= k)
        //         sub.erase(sub.find(nums[left++]));
        //     sub.insert(nums[right++]);
        //     ret.push_back(*sub.begin());
        // }
        // return ret;

        // best solution
        deque<int> dq;
        vector<int> ret;
        for (int right = 0; right < nums.size(); right++) {
            while (!dq.empty() && nums[dq.back()] <= nums[right])
                dq.pop_back();
            dq.push_back(right);
            if (dq.front() <= right - k)
                dq.pop_front();
            if (right >= k - 1)
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};
