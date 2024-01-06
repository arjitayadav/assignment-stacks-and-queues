#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::vector<int> nums = {4, 2, 10, 8, 1, 6, 5};
    int n = nums.size();
    
    std::vector<int> result(n, -1);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i]; 
            st.pop();
        }
        st.push(i);
    }

    std::cout << "Next greater elements are: ";
    for (int i : result) {
        std::cout << i << " ";
    }

    return 0;
}


