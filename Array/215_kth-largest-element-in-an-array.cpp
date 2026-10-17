/*
LeetCode 215 — Kth Largest Element in an Array
Pattern: Heap + Priority Queue (Min Heap)
Approach:
- Use a Min Heap to maintain the k largest elements.
- Create a Min Heap:
    `priority_queue<int, vector<int>, greater<int>> pq`
- Iterate through every number in `nums`:
    - Push the number into the heap.
    - If `pq.size() > k`:
        → Remove the smallest element using `pq.pop()`.
- After processing all numbers:
    → The heap contains the k largest elements.
    → The smallest element in the heap is the kth largest element.
- Return `pq.top()`.
Key Insight:
- The Min Heap keeps at most k elements.
- When the heap size exceeds k, remove the smallest element.
- Larger elements remain in the heap.
- The heap's top is the smallest among the k largest elements.
- No need to sort the entire array.
Example:
    nums = [3,2,1,5,6,4]
    k = 2
    Process:
    3 → [3]
    2 → [2,3]
    1 → [2,3]       (remove 1)
    5 → [3,5]       (remove 2)
    6 → [5,6]       (remove 3)
    4 → [5,6]       (remove 4)
    pq.top() = 5
    Answer: 5
    
Takeaway:
- 215 → Heap + Priority Queue.
- Use a Min Heap to find the kth largest element.
- Maintain exactly k elements after each iteration.
- If size > k → pop the smallest element.
- `pq.top()` → kth largest element.
- More efficient than sorting the entire array when k is small.=
Complexity:
- Time: O(n log k)
    - Each push/pop takes O(log k) when the heap is bounded by k.
- Space: O(k)
    - The heap stores at most k elements.
*/
class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end(), std::greater<int>());
    //     return nums[k - 1];
    // }
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
