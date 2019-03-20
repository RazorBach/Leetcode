//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		stack_;
		min_ = INT_MAX;
	}

	void push(int x) {
		if (empty()) {
			stack_.push(x);
			min_ = x;
			return;
		}
		if (x >= min_)
			stack_.push(x);
		else {
			stack_.push(2 * x - min_);
			min_ = x;
		}
	}

	void pop() {
		if (empty())
			throw std::out_of_range("empty stack");
		int top = stack_.top();
		stack_.pop();
		if (min_ == INT_MIN || top < min_)
			min_ = 2 * min_ - top;
	}

	int top() {
		if (empty())
			throw std::out_of_range("empty stack");
		int top = stack_.top();
		if (min_ == INT_MIN || top < min_)
			return min_;
		return top;
	}

	int getMin() {
		return min_;
	}

	bool empty() {
		return stack_.empty();
	}
private:
	std::stack<int> stack_;
	int min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
