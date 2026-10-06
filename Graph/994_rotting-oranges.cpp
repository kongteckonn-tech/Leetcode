/* LeetCode 994 — Rotting Oranges
Pattern: Graph + BFS + Multi-source Shortest Path
Approach:
*  Scan the grid:
    - Put all initial rotten oranges (val == 2) into a Queue[cite: 1].
    - Count total fresh oranges (val == 1)[cite: 1].
*  If total fresh oranges == 0:
    - Return 0 (no oranges need to rot)[cite: 1].
*  Perform Multi-source BFS level by level:
    - Track time/minutes passed (each level = 1 minute)[cite: 1].
    - For each rotten orange in the queue, check its 4 directional neighbors (up, down, left, right)[cite: 1].
    - If neighbor is fresh (val == 1):
        - Change state to rotten (val = 2)[cite: 1].
        - Decrement fresh orange count[cite: 1].
        - Add neighbor coordinates to Queue[cite: 1].
*  After BFS finishes:
    - If fresh orange count > 0 -> return -1 (some oranges couldn't be reached)[cite: 1].
    - Otherwise -> return elapsed minutes (time - 1)[cite: 1].

Key Insight:
*  All rotten oranges rot adjacent fresh oranges simultaneously at each minute[cite: 1].
*  This is a classic Multi-source BFS problem; starting BFS from all initial rotten oranges concurrently finds the shortest time to rot every reachable orange[cite: 1].
*  Level-by-level queue processing ensures time steps are tracked accurately[cite: 1].

Example:
*  grid = [[2,1,1],[1,1,0],[0,1,1]][cite: 1]
*  Initial Queue: [(0,0)], Fresh count: 6[cite: 1]
*  Minute 1: (0,0) rots (0,1) and (1,0) -> Fresh count: 4, Queue: [(0,1), (1,0)][cite: 1]
*  Minute 2: rots (0,2) and (1,1) -> Fresh count: 2, Queue: [(0,2), (1,1)][cite: 1]
*  Minute 3: rots (1,2) -> Fresh count: 1, Queue: [(1,2)][cite: 1]
*  Minute 4: rots (2,2) -> Fresh count: 0, Queue: [(2,2)][cite: 1]
*  Result: 4 minutes[cite: 1].

Takeaway:
*  994 -> Graph + Multi-source BFS[cite: 1].
*  Start queue with all rotten oranges initially to process simultaneous spreading[cite: 1].
*  Track fresh count to easily verify if any oranges remain unrotten at the end[cite: 1].

Complexity:
*  Time: O(M * N)     - Each cell is visited a constant number of times[cite: 1].
*  Space: O(M * N)    - Queue can store up to M * N cell coordinates in the worst case[cite: 1]. */
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;

        // Step 1: Initialize Queue with all rotten oranges & count fresh ones
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        // If no fresh oranges exist, 0 minutes needed
        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Multi-source BFS
        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size();
            minutes++;

            for (int i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // Check bounds and if neighbor is a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot the fresh orange
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        // Step 3: Check if all fresh oranges rotted
        return freshCount == 0 ? minutes : -1;
    }
};
