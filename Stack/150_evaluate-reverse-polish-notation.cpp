/*
Pattern: Stack

Approach:
- Traverse the tokens from left to right.
- If the token is a number:
    - Convert it using stoi() or queue.
    - Push it onto the stack.
- If the token is an operator:
    - Pop the top two numbers.
    - Apply the operation in the order:
        left_operand operator right_operand.
    - Push the result back onto the stack.
- After processing all tokens,
  the stack contains the final answer.

Key Insight:
- Reverse Polish Notation eliminates the need for parentheses.
- Operators always apply to the two most recent operands.
- Since the stack is LIFO, pop the right operand first,
  then the left operand.

Complexity:
- Time: O(n)
    - Each token is processed exactly once.
- Space: O(n)
    - In the worst case, all numbers are stored in the stack.

Takeaway:
- When an expression is evaluated from left to right
  and always uses the most recent values,
  think → Stack.
- Pay attention to operand order:
    b = pop(), a = pop(), then compute a op b.
*/
#include<stack>
#include<queue>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> reserve;
        queue<int> convert;
        for (int i = 0; i < tokens.size(); i++)
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                int sum = 0;
                for (int j = tokens[i].size() - 1, index = 1; j >= 0; j--, index *= 10)
                {
                    if ((tokens[i])[j] == '-')
                    {
                        sum *= -1;
                        continue;
                    }
                    sum += ((tokens[i])[j] - '0') * index;
                }
                convert.push(sum);
            }
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                reserve.push(convert.front());
                convert.pop();
            }
            else
            {
                if (tokens[i] == "+")
                {
                    int index2 = reserve.top();
                    reserve.pop();
                    int index1 = reserve.top();
                    reserve.pop();
                    reserve.push(index1 + index2);
                }
                else if (tokens[i] == "-")
                {
                    int index2 = reserve.top();
                    reserve.pop();
                    int index1 = reserve.top();
                    reserve.pop();
                    reserve.push(index1 - index2);
                }
                else if (tokens[i] == "*")
                {
                    int index2 = reserve.top();
                    reserve.pop();
                    int index1 = reserve.top();
                    reserve.pop();
                    reserve.push(index1 * index2);
                }
                else if (tokens[i] == "/")
                {
                    int index2 = reserve.top();
                    reserve.pop();
                    int index1 = reserve.top();
                    reserve.pop();
                    reserve.push((int)(index1 / index2));
                }
            }
        }
        return reserve.top();
    }
};
