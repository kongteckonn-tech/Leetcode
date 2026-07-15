/*
Pattern: Arrays
Idea:
- Simulate the addition just like elementary school math.
- Start from the least significant digit (the end of the array).
- Initialize carry (extra) = 1 because we are adding one.
- Traverse from back to front:
    - Add carry to the current digit.
    - If the result is 10:
        Set the digit to 0.
        Keep carry = 1.
    - Otherwise:
        Update the digit.
        Set carry = 0.
- If there is still a carry after processing all digits:
    Insert a leading 1.

My Approach:
- Used a stack to reverse the processed digits.
- Store the final digits in another vector before returning.
- This works correctly but uses unnecessary extra space.

Optimal Approach:
- Traverse from the last digit.
- If the current digit is less than 9:
    Increment it and return immediately.
- Otherwise:
    Set it to 0 and continue.
- If every digit is 9:
    Insert 1 at the beginning of the vector.

Key Insight:
- Carry only propagates while the current digit is 9.
- Once a digit becomes less than 10 after adding one, the process is finished.
- Early return avoids unnecessary traversal.
- No stack or extra vector is required because the digits can be modified directly.

Key STL:
vector<int>

Time:
- My approach: O(n)
- Optimal approach: O(1)
Space:
- My approach: O(n)
    - Uses a stack and an extra vector.
- Optimal approach: O(1)
    - Modifies the original vector in-place.

Mistakes:
- Initially used a stack and another vector even though the original vector could be modified directly.
- Didn't realize the algorithm can return immediately once the carry disappears.
- Used extra memory for reversing the digits unnecessarily.

Takeaway:
- For digit addition problems:
    Think → Process from the Least Significant Digit.
- Carry propagates only while digits are 9.
- When modifying an array in-place is allowed, avoid extra data structures unless necessary.
- Always consider whether an early return can reduce unnecessary work.
*/
#include<stack>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int extra = 1;
        stack<int> tmp;
        vector<int> ret;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += extra;
            if (digits[i] >= 10){
                digits[i] -= 10;
                extra = 1;
            }
            else extra = 0;
            tmp.push(digits[i]);
        }
        if (extra == 1)
            tmp.push(1);
        while (!tmp.empty())
        {
            ret.push_back(tmp.top());
            tmp.pop();
        }
        return ret;
    }
};
// best
/*
vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
}
*/
