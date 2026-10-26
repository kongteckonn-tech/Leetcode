/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
#include<queue>
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    void addNum(int num) {
        if (maxHeap.empty() && minHeap.empty())
            maxHeap.push(num);
        else
        {
            maxHeap.top() < num ? minHeap.push(num) : maxHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (maxHeap.size() + 1 < minHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    double findMedian() {
        if (minHeap.empty() && maxHeap.empty())
            return 0.0;
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        else 
            return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
/*
LeetCode 295 - Find Median from Data Stream

Pattern:
- Two Heaps (Max Heap + Min Heap)
- Priority Queue
- Dynamic Median

Approach:
- Use maxHeap to store the smaller half of numbers.
- Use minHeap to store the larger half of numbers.
- Insert each new number into the appropriate heap.
- Rebalance the heaps if their sizes differ by more than 1.
- Find the median using the top elements of the heaps.

Key Insight:
- maxHeap.top() gives the largest number in the smaller half.
- minHeap.top() gives the smallest number in the larger half.
- All elements in maxHeap must be <= all elements in minHeap.
- The size difference between the two heaps must be <= 1.
- If total size is odd, the median is the top of the larger heap.
- If total size is even, the median is the average of both tops.
- No need to sort the entire data stream.

Example:
Input: addNum(1), addNum(2), addNum(3)

Step 1:
- maxHeap = [1]
- minHeap = []
- Median = 1

Step 2:
- maxHeap = [1]
- minHeap = [2]
- Median = (1 + 2) / 2 = 1.5

Step 3:
- maxHeap = [1, 2]
- minHeap = [3]
- Median = 2

Takeaway:
- Use two heaps to maintain the smaller and larger halves.
- Max Heap provides the left boundary of the median.
- Min Heap provides the right boundary of the median.
- Balance heap sizes after every insertion.
- Always check heap emptiness before calling top().
- Convert to double before adding heap tops to avoid integer overflow.
- Two Heaps is useful for dynamic median problems.

Complexity:
- addNum(): O(log n)
- findMedian(): O(1)
- Space: O(n)
*/
