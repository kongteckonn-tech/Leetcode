/*
Pattern: Stack

Idea:
- Implement a stack using a dynamic array.
- Store elements in `_data` and expand the array when it becomes full.
- `push()` adds an element to the top.
- `pop()` removes the top element.
- `top()` returns the last inserted element.
- `getMin()` scans the entire stack to find the smallest value.

My Approach:
- Built the stack manually instead of using STL `stack`.
- Used a dynamic array with automatic capacity doubling.
- Implemented stack operations using the `_size` index.
- For `getMin()`, traversed all elements to find the minimum.

Key Insight:
- Stack operations (push, pop, top) are naturally O(1).
- Finding the minimum by scanning the stack is O(n), which does not satisfy the problem requirement.
- Precomputing the minimum at every stack level allows constant-time retrieval.
- Extra space is traded for faster queries.

Key STL:
- (Current implementation)
    None (manual dynamic array)
- (Optimal implementation)
    stack<int>

Time:
- push(): O(1) amortized
- pop(): O(1)
- top(): O(1)
- getMin(): O(n)
Space:
- My approach: O(n)
    - Stores all elements in a dynamic array.
- Optimal approach: O(n)
    - Uses one additional stack to store the running minimum.

Mistakes:
- Implemented `getMin()` by scanning the entire stack, resulting in O(n).
- Initially focused only on storing the stack values instead of maintaining the minimum value.
- `AddCap()` replaces `_data` without deleting the old array, causing a memory leak.
- Missing a destructor to release dynamically allocated memory.

Takeaway:
- When a problem requires repeated minimum/maximum queries:
    Think → Maintain auxiliary information while updating the data structure.
- Don't recompute values that can be updated incrementally.
- Always check whether the required time complexity is achievable with a better data structure design.
*/
class MinStack {
private:
    int* _data;
    int _size;
    int _capacity;
    void AddCap(int* data)
    {
        int* array = new int[2 * this->_capacity];
        for (int i = 0; i < _capacity; i++)
            array[i] = data[i];
        this->_data = array;
        this->_capacity *= 2;
    }
public:
    MinStack() : _size(0), _capacity(1) {
        this->_data = new int[1];
    }
    void push(int value) {
        if (this->_size == this->_capacity)
            AddCap(this->_data);
        this->_data[this->_size++] = value;
    }
    void pop() {
        if (_size == 0)
            return;
        _size--;
    }
    int top() {
        return this->_data[this->_size - 1];
    }
    int getMin() {
        int min = this->_data[0];
        for (int i = 1; i < this->_size; i++)
            min = min < this->_data[i] ? min : this->_data[i];
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
