/*
Pattern: Monotonic Decreasing Stack
Approach:
- Store indices in the stack instead of temperatures.
- The stack keeps temperatures in decreasing order.
- When a higher temperature is found:
    - Pop all smaller temperatures.
    - Calculate the waiting days.
    - Update their answers.
- Push the current index into the stack.
- Remaining indices in the stack have no warmer future day,
  so their answers stay 0.

Key Insight:
- A future warmer temperature can solve multiple previous days.
- Store unresolved indices and process them when a warmer
  temperature appears.
- Using indices allows direct calculation of the distance.

Complexity:
- Time: O(n)
    - Each index is pushed and popped at most once.
- Space: O(n)
    - In the worst case, the stack stores all indices.

Takeaway:
- When searching for the next greater element,
  think → Monotonic Stack.
- Store indices when the problem requires distances or positions.
*/
#include<stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> tem;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!(tem.empty()) && temperatures[i] > temperatures[tem.top()])
            {
                ret[tem.top()] = i - (int)tem.top();
                tem.pop();
            }
            tem.push(i);
        }
        return ret;
    }
};
