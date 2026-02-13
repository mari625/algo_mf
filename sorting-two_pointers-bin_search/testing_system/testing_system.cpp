#include <iostream>
#include <vector>
#include <algorithm>

struct Result {
    int quantity = 0;
    int penny = 0;
    int number = 0;

    bool operator==(Result other) const {
        return number == other.number && penny == other.penny && quantity == other.quantity;
    }

    bool operator<(Result other) const {
        if (quantity == other.quantity && penny == other.penny) {
            return number < other.number;
        }
        if (quantity == other.quantity) {
            return penny < other.penny;
        }
        return quantity > other.quantity;
    }
};

int main() {
    int number = 0;
    std::cin >> number;

    std::vector<Result> results(number);
    for (int i = 0; i < number; ++i) {
        std::cin >> results[i].quantity >> results[i].penny;
        results[i].number = i + 1;
    }

    std::sort(results.begin(), results.end());

    for (int i = 0; i < number; ++i) {
        std::cout << results[i].number << " ";
    }
    std::cout << '\n';

    return 0;
}
