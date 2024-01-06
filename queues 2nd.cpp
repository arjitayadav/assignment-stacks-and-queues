#include <iostream>
#include <queue>
#include <unordered_set>

class ConsecutiveFinder {
private:
    std::queue<int> dataQueue;
    std::unordered_set<int> uniqueNumbers;

public:
    void insert(int num) {
        if (uniqueNumbers.find(num) == uniqueNumbers.end()) {
            dataQueue.push(num);
            uniqueNumbers.insert(num);
        }
    }

    void findConsecutive() {
        int consecutiveCount = 0;

        while (!dataQueue.empty()) {
            int currentNumber = dataQueue.front();
            dataQueue.pop();
            while (uniqueNumbers.find(currentNumber + 1) != uniqueNumbers.end()) {
                consecutiveCount++;
                currentNumber++;
            }
            if (consecutiveCount > 1) {
                std::cout << "Consecutive Sequence Found: ";
                for (int i = currentNumber - consecutiveCount + 1; i <= currentNumber; ++i) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }

            consecutiveCount = 0;
        }
    }
};

int main() {
    ConsecutiveFinder consecutiveFinder;
    consecutiveFinder.insert(1);
    consecutiveFinder.insert(2);
    consecutiveFinder.insert(4);
    consecutiveFinder.insert(5);
    consecutiveFinder.insert(6);
    consecutiveFinder.insert(8);

    consecutiveFinder.findConsecutive();

    return 0;
}