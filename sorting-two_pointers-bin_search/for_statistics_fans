#include <iostream>
#include <vector>
#include <algorithm>

struct City {
    int quantity = 0;
    int index = 0;

    bool operator==(City other) const {
        return quantity == other.quantity;
    }

    bool operator<(City other) const {
        if (quantity == other.quantity) {
            return index < other.index;
        }
        return quantity < other.quantity;
    }
};

void FindX(int small, int big, int x_val, std::string& answer, std::vector<City>& cities) {
    auto lower = std::lower_bound(cities.begin(), cities.end(), City{x_val, small});
    auto upper = std::upper_bound(cities.begin(), cities.end(), City{x_val , big});
    if (lower < upper) {
        answer += '1';
    } else {
        answer += '0';
    }
}

int main() {
    int number = 0;
    std::cin >> number;

    std::vector<City> cities(number);

    for (int i = 0; i < number; ++i) {
        std::cin >> cities[i].quantity;
        cities[i].index = i;
    }

    std::sort(cities.begin(), cities.end());

    int number_of_queries = 0;
    std::cin >> number_of_queries;

    std::string answer;

    for (int i = 0; i < number_of_queries; ++i) {
        int left = 0;
        int right = 0;
        int x_val = 0;
        std::cin >> left >> right >> x_val;

        FindX(left - 1, right - 1, x_val, answer, cities);
    }

    std::cout<<answer<<'\n';

    return 0;
}
