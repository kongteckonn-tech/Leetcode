/* LeetCode 127 — Word Ladder
Pattern: Graph + BFS + Shortest Path
Approach:
*  Store all words in an Unordered Set for O(1) lookups.
*  Use BFS with a Queue to find the shortest transformation sequence length.
*  For each level in BFS:
    - Increment length/step count by 1.
    - For each word in the current level, generate all possible 1-letter mutated words:
        - Change each character from 'a' to 'z'.
        - If new word == endWord -> return step count + 1.
        - If new word exists in set:
            - Push new word into Queue.
            - Erase new word from set (prevents revisiting and acts as visited set).
*  If Queue becomes empty and endWord was not reached -> return 0.

Key Insight:
*  Finding the shortest transformation sequence in an unweighted graph is a classic BFS problem.
*  Instead of comparing all pairs of words (O(N^2 * L)), mutate each character of the current word ('a' through 'z') and check existence in set (O(N * L * 26)).
*  Level-by-level BFS guarantees the first time endWord is reached, it is via the shortest path.

Example:
*  beginWord = "hit", endWord = "cog"
*  wordList = ["hot","dot","dog","lot","log","cog"]
*  Level 1: "hit" -> mutates to "hot" -> Queue: ["hot"]
*  Level 2: "hot" -> mutates to "dot", "lot" -> Queue: ["dot", "lot"]
*  Level 3: "dot" -> "dog", "lot" -> "log" -> Queue: ["dog", "log"]
*  Level 4: "dog" -> "cog" -> Match found! -> Return 5 (hit -> hot -> dot -> dog -> cog).

Takeaway:
*  127 -> Graph + BFS + Shortest Path.
*  BFS ensures shortest distance in unweighted graphs.
*  Mutate each character ('a'-'z') + hash set lookup is faster than pairwise comparison.
*  Erase visited words from the set directly to save space and avoid cycle loops.

Complexity:
*  Time: O(N * L * 26) = O(N * L)  - N is wordList size, L is word length.
*  Space: O(N * L)                  - Queue and Hash Set storage. */
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in wordList, transformation is impossible
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        
        int steps = 1; // Start counting from 1 (beginWord itself counts as length 1)

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                string current = q.front();
                q.pop();

                // Try mutating every character of the current word
                for (int j = 0; j < current.length(); ++j) {
                    char originalChar = current[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        
                        current[j] = c;

                        // Found target word
                        if (current == endWord) {
                            return steps + 1;
                        }

                        // If mutated word exists in set, push to queue and remove to mark as visited
                        if (wordSet.count(current)) {
                            q.push(current);
                            wordSet.erase(current);
                        }
                    }

                    current[j] = originalChar; // Restore character
                }
            }
            steps++;
        }

        return 0;
    }
};
