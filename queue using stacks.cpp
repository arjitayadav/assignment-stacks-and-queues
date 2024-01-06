#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> enqueueStack;
    std::stack<int> dequeueStack;

public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    int dequeue() {
        if (enqueueStack.empty() && dequeueStack.empty()) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; 
        }

        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        int frontElement = dequeueStack.top();
        dequeueStack.pop();
        return frontElement;
    }

    bool isEmpty() const {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};

int main() {
    QueueUsingStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}