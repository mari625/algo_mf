#include <functional>
#include <iostream>
#include <queue>
#include <string>

void SimulateHeap(int number) {
    std::priority_queue<int> big_max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> big_min_heap;
    std::priority_queue<int> small_max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_min_heap;

    const int kT = 7;

    for (int i = 0; i < number; ++i) {
        std::string query;
        std::getline(std::cin, query);

        if (query[0] == 'I') {
            std::string substring = query.substr(kT);
            substring.erase(substring.end() - 1);
            int elem = std::stoi(substring);

            big_max_heap.push(elem);
            big_min_heap.push(elem);
        } else if (query[4] == 'i') {
            std::cout << big_min_heap.top() << '\n';

            small_max_heap.push(big_min_heap.top());
            big_min_heap.pop();
        } else {
            std::cout << big_max_heap.top() << '\n';

            small_min_heap.push(big_max_heap.top());
            big_max_heap.pop();
        }

        while (!small_min_heap.empty() && big_min_heap.top() == small_min_heap.top()) {
            small_min_heap.pop();
            big_min_heap.pop();
        }

        while (!small_max_heap.empty() && big_max_heap.top() == small_max_heap.top()) {
            small_max_heap.pop();
            big_max_heap.pop();
        }
    }
}

int main() {
    std::string number;

    std::getline(std::cin, number);

    SimulateHeap(std::stoi(number));

    return 0;
}
