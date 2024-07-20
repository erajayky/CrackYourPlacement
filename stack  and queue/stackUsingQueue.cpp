class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        q.push(x);
        int size = q.size() - 1;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};