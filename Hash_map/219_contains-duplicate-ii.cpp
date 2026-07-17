/*
Pattern: Sliding Window + Hash Map (Best) / Hash Map with last-index (Cleanest)
Idea:
      First idea:
      - For each index i, scan forward up to k steps and use a map to
        detect duplicates within that window, clearing the map each outer iteration.
      - Time complexity is O(n*k), too slow for large k.

      Second idea (Sliding Window):
      - Maintain a window of size k+1 using two pointers (slow, fast).
      - Use a map to count occurrences of each number inside the window.
      - When fast pointer moves in, increment count; if count reaches 2, found duplicate.
      - When window exceeds size k+1, decrement count for the element leaving (slow pointer).
      - O(n) time, O(min(n,k)) space.

      Best / Cleanest idea:
      - Use a hash map storing value -> last seen index.
      - For each i, check if nums[i] was seen before and if i - lastIndex <= k.
      - If yes, return true; otherwise update lastIndex[nums[i]] = i.
      - Avoids explicit window maintenance (no need to decrement/remove),
        same O(n) time and O(min(n, distinct values)) space, but simpler logic.
Key STL: unordered_map
Time:
      - Brute Force: O(n*k)
      - Sliding Window (count-based): O(n)
      - Hash Map (last-index): O(n)
Space:
      - Brute Force: O(k) (map cleared each outer loop)
      - Sliding Window: O(min(n, k+1))
      - Hash Map (last-index): O(min(n, distinct values))
Mistakes:
      - None major — sliding window logic is correct, just more verbose
        than necessary since counting isn't required, only "does a duplicate
        exist within distance k" — a single last-seen-index check suffices.
Takeaway:
      - When the question is "does X exist within a distance", storing the
        last index (not a count) is usually cleaner than a full sliding window.
      - Sliding window is still valuable when you need to know *how many*
        times something appears in a window, not just whether a duplicate exists.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /* First idea*/
        // unordered_map<int, int> mp;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i; j < nums.size() && j < k + i + 1; j++)
        //     {
        //         mp[nums[j]]++;
        //         if (mp[nums[j]] == 2)
        //             return true;
        //     }
        //     mp.clear();
        // }
        // return false;

        /* Second idea*/
        // int slow = 0, fast = 0;
        // unordered_map<int, int> mp;
        // while (fast < nums.size() && fast < k + 1)
        // {
        //     mp[nums[fast]]++;
        //     if (mp[nums[fast]] == 2)
        //         return true;
        //     fast++;
        // }
        // if (nums.size() < k + 1)
        //     return false;
        // while (fast < nums.size())
        // {
        //     mp[nums[slow++]]--;
        //     mp[nums[fast]]++;
        //     if (mp[nums[fast]] == 2)
        //         return true;
        //     fast++;
        // }
        // return false;

        //best
        unordered_map<int, int> lastIndex;  // value -> 最近一次出现的下标
        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.count(nums[i]) && i - lastIndex[nums[i]] <= k)
                return true;
            lastIndex[nums[i]] = i;  // 更新/插入最新下标
        }
        return false;
    }
};
