#include <iostream>
#include <deque>
#include <vector>

void FindMin(int number, int length, const std::vector<int>& arr) {
    std::deque<int> window;

    for (int i = 0; i < length; ++i) {
        while (!window.empty() && arr[i] < window.back()) {
            window.pop_back();
        }
        window.push_back(arr[i]);
    }

    std::cout << window.front() << '\n';

    for (int i = 0; i < number - length; ++i) {
        if (!window.empty() && arr[i] == window.front()) {
            window.pop_front();
        }
        
        while (!window.empty() && arr[i + length] < window.back()) {
            window.pop_back();
        }
        window.push_back(arr[i + length]);

        std::cout << window.front() << '\n';
    }
}

int main() {
    int number = 0;
    int length = 0;

    std::cin >> number >> length;

    std::vector<int> arr(number);

    for (int i = 0; i < number; ++i) {
        std::cin >> arr[i];
    }

    FindMin(number, length, arr);
    return 0;
}
