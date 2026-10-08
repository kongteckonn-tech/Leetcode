/* LeetCode 752 — Open the Lock
Pattern: Graph + BFS + Shortest Path
Approach:
*  Store all deadends in an Unordered Set for O(1) lookups and visited tracking[cite: 1].
*  Check base conditions:
    - If "0000" or target is in deadends -> return -1 immediately.
*  Use BFS with a Queue to find the minimum number of wheel turns (shortest path)[cite: 1]:
    - Push "0000" into Queue and mark as visited[cite: 1].
    - Level-by-level BFS traversal:
        - For each lock state in current level:
            - If current state == target -> return current step count.
            - For each of the 4 wheel positions:
                - Mutate wheel position upward (+1, '9' loops to '0').
                - Mutate wheel position downward (-1, '0' loops to '9').
                - If new state is not visited:
                    - Push into Queue and add to visited set[cite: 1].
                - Restore original character before moving to next position[cite: 1, 2].
        - Increment step count by 1 after each full level.
*  If Queue becomes empty and target was not reached -> return -1[cite: 1].

Key Insight:
*  Finding the minimum turns to unlock in an unweighted state space is a classic BFS problem[cite: 1].
*  Each 4-digit lock state has exactly 8 neighboring states (4 positions * 2 turn directions)[cite: 1].
*  Adding states to visited immediately upon pushing into Queue prevents redundant level visits and cycle loops.

Example:
*  deadends = ["0201","0101","0102","1212","2002"], target = "0202"
*  Level 0: "0000" -> Step 0
*  Level 1: "1000", "9000", "0100", "0900", "0010", "0090", "0001", "0009" -> Step 1
*  Level 6: Reaches "0202" -> Return 6.

Takeaway:
*  752 -> Graph + BFS + Shortest Path[cite: 1].
*  Level-by-level BFS guarantees the first time target is popped/reached, it is via the shortest path.
*  Proper char restoration during neighbor generation ensures valid state transitions[cite: 1, 2].
*  Use deadends set as part of visited set for space/lookup efficiency[cite: 1].

Complexity:
*  Time: O(10^4 * 8) = O(1)     - Total 10,000 possible lock states, each expanding up to 8 neighbors.
*  Space: O(10^4) = O(1)        - Queue and Hash Set store at most 10,000 states. */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        // Impossible to unlock when "0000" and target appear in visited
        if (visited.count("0000") || visited.count(target))
            return -1;
        
        // create a queue to store possible num
        queue<string> que;
        que.push("0000");
        visited.insert("0000"); // start point recorded
        int step = 0;
        // stop loop when que is empty
        while (!que.empty())
        {
            int level = que.size(); // current level of que
            for (int l = 0; l < level; l++)
            {
                string cur = que.front();
                que.pop();
                if (cur.compare(target) == 0)
                    return step;
                // run loop with 4 positions 
                for (int i = 0; i < cur.length(); i++) 
                {
                    char ori = cur[i];
                    // 1. (+1)
                    cur[i] = (ori == '9') ? '0' : ori + 1;
                    if (visited.find(cur) == visited.end())
                    {
                        que.push(cur);
                        visited.insert(cur);
                    }
                    // 2. (-1)
                    cur[i] = (ori == '0') ? '9' : ori - 1;
                    if (visited.find(cur) == visited.end())
                    {
                        que.push(cur);
                        visited.insert(cur);
                    }
                    // 3. reset the cur string
                    cur[i] = ori;
                }
            }
            step++; // step increase
        }
        return -1;
    }
};
