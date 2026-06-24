#include <queue>

class MyStack {
public:
    std::queue<int> s1;

    MyStack() {

    }

    void push(int x) {
        s1.push(x);

        // Rotate the elements to make the recently pushed element at the front
        for (int i = 0; i < s1.size() - 1; ++i) {
            s1.push(s1.front());
            s1.pop();
        }
    }

    int pop() {
        int topElement = s1.front();
        s1.pop();
        return topElement;
    }

    int top() {
        return s1.front();
    }

    bool empty() {
        return s1.empty();
    }
};
