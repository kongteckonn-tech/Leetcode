/*
Pattern: Hash Map + Heap

Idea:
When I see the question I first think about counting frequency of each number.
Then I know I need to pick the top k frequent elements, but I am not familiar with how to use STL heap properly.
So I:
      - use unordered_map to store frequency (num -> count)
      - then try to use priority_queue to sort frequency
      - store (frequency, number) in heap
      - pop k times to get result

Key Insight:
- Convert array into frequency map first
- Then select top k frequent elements

Key STL:
unordered_map<int,int>, priority_queue<pair<int,int>>, vector<int>

Time: O(n log n)
Space: O(n)

Mistakes:
- Not familiar with priority_queue usage
- Not熟 STL, especially heap and pair usage
- Initially don't know how to sort by frequency

Takeaway:
- Need to practice STL more (especially unordered_map and priority_queue)
- "Top K" problems usually use heap or bucket
*/
#include<map>
#include<queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k > nums.size())
            return nums;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& it : mp) {
            int num = it.first;
            int freq = it.second;
            pq.push({freq, num});
        }
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
