#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct NumberWithPos {
    int number = 0;
    int pos = 0;

    bool operator< (NumberWithPos other) const {
        return number > other.number;
    }

    bool operator== (NumberWithPos other) const {
        return number == other.number;
    }
};

void FindGoodPeriod(int number) {
    std::vector<int64_t> prefix_sums(number + 1);
    prefix_sums[0] = 0;

    std::priority_queue<NumberWithPos> heap;
    std::set<int> used_positions;

    int64_t max_happiness = 0;
    int left = 1;
    int right = 1;

    for (int i = 0; i < number; ++i) {
        int elem = 0;
        std::cin >> elem;

        prefix_sums[i + 1] = prefix_sums[i] + elem;

        heap.push(NumberWithPos{elem, i});
    }

    while (!heap.empty()) {
        int current_min = heap.top().number;
        int current_pos = heap.top().pos;

        heap.pop();

        int left_border = -1;
        int right_border = number;

        auto lower = used_positions.lower_bound(current_pos);

        if (lower != used_positions.end()) {
            right_border = *(lower);
        }

        if (lower != used_positions.begin()) {
            left_border = *(--lower);
        }
        
        int64_t current_sum = prefix_sums[right_border] - prefix_sums[left_border + 1];

        if (max_happiness < current_min*current_sum) {
            max_happiness = current_min*current_sum;

            if (left_border == -1) {
                left = 1;
            } else {
                left = left_border + 2;
            }

            if (right_border == number) {
                right = number;
            } else {
                right = right_border;
            }
        }

        used_positions.insert(current_pos);
    }

    std::cout << max_happiness << '\n';
    std::cout << left << " " << right <<'\n';
}

int main() {
    int number = 0;

    std::cin >> number;

    FindGoodPeriod(number);

    return 0;
}
