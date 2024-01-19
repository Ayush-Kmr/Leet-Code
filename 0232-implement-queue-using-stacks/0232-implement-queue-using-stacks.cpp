class MyQueue {
     private:
  stack<int> input;
  stack<int> output;
 public:
  void push(int x) {
    input.push(x);
  }

  int pop() {
    peek();
    const int val = output.top();
    output.pop();
    return val;
  }

  int peek() {
    if (output.empty())
      while (!input.empty())
        output.push(input.top()), input.pop();
    return output.top();
  }

  bool empty() {
    return input.empty() && output.empty();
  }


};