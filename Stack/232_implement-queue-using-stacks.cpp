/*
Pattern: Two Stacks

Approach:
- Use two stacks:
    - input: stores newly pushed elements.
    - output: provides front elements for pop() and peek().
- push():
    - Push the element into the input stack.
- pop() / peek():
    - If the output stack is empty:
        - Move all elements from input to output.
    - Access the top of the output stack.
- empty():
    - The queue is empty only when both stacks are empty.

Key Insight:
- The input stack stores elements in insertion order.
- Moving all elements to the output stack reverses their order,
  making the oldest element appear on top.
- Each element is moved from input to output at most once.

Complexity:
- Time:
    - push(): O(1)
    - pop(): O(1) amortized
    - peek(): O(1) amortized
    - empty(): O(1)
- Space: O(n)
    - Two stacks together store all elements.

Takeaway:
- When FIFO behavior must be implemented using LIFO structures,
  think → Two Stacks.
- Delay transferring elements until the output stack is empty
  to achieve amortized O(1) operations.
*/
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {}
    void push(int x) {
        in.push(x);
    }
    int pop() {
        peek();
        int x = out.top();
        out.pop();
        return x;
    }
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    bool empty() {
        return in.empty() && out.empty();
    }
};
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
