#include <iostream>
#include <stack>
#include <unordered_set>

void removeDuplicates(std::stack<int>& originalStack) {
    std::stack<int> tempStack;
    std::unordered_set<int> seenElements;
    while (!originalStack.empty()) {
        int currentElement = originalStack.top();
        originalStack.pop();

        if (seenElements.find(currentElement) == seenElements.end()) {
            tempStack.push(currentElement);
            seenElements.insert(currentElement);
        }
    }
    while (!tempStack.empty()) {
        originalStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    std::stack<int> originalStack;
    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);
    originalStack.push(2);
    originalStack.push(4);
    originalStack.push(3);
    originalStack.push(5);

    std::cout << "Original Stack: ";
    while (!originalStack.empty()) {
        std::cout << originalStack.top() << " ";
        originalStack.pop();
    }
    std::cout << std::endl;
    removeDuplicates(originalStack);

    std::cout << "Stack after removing duplicates: ";
    while (!originalStack.empty()) {
        std::cout << originalStack.top() << " ";
        originalStack.pop();
    }
    std::cout << std::endl;

    return 0;
}