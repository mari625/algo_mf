#include <iostream>
#include <queue>

void FindDrinker(int number, std::queue<int>& first, std::queue<int>& second) {
    int counter = 0;
    const int kMax = 200'000;

    while (!first.empty() && !second.empty() && counter <= kMax) {
        if ((first.front() == 0 && second.front() == number - 1) || (first.front() > second.front() && (second.front() != 0 || first.front() != number - 1))) {
            first.push(first.front());
            first.push(second.front());
        } else {
            second.push(first.front());
            second.push(second.front());
        }

        first.pop();
        second.pop();

        counter ++;
    }

    if (first.empty()) {
        std::cout << "second " << counter << '\n';
        return;
    }

    if (second.empty()) {
        std::cout << "first " << counter << '\n';
        return;
    }

    std::cout << "draw" << '\n';
}

int main() {
    int number = 0;

    std::cin >> number;

    std::queue<int> first;
    std::queue<int> second;

    for (int i = 0; i < number / 2; ++i) {
        int elem = 0;
        std::cin >> elem;

        first.push(elem);
    }

    for (int i = 0; i < number / 2; ++i) {
        int elem = 0;
        std::cin >> elem;

        second.push(elem);
    }

    FindDrinker(number, first, second);
    return 0;
}
