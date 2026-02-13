#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

uint32_t x0 = 0;
uint32_t x1 = 0;
uint32_t a = 0;
uint32_t b = 0;
uint32_t c = 0;


uint32_t next() {
    uint32_t t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

struct ElementWithIndex {
    uint32_t value;
    uint32_t index;

    bool operator< (const ElementWithIndex& other) const {
        return value > other.value;
    }

    bool operator== (const ElementWithIndex& other) const {
        return value == other.value;
    }
};

uint32_t AskMin(uint32_t number, uint32_t number_queries) {
    uint32_t sum = 0;
    const uint32_t kMax = 4'294'967'295;
    const uint32_t kConst = 10099;
    uint32_t cur_power = kConst;
    uint32_t cur_min = kMax;

    std::vector<uint32_t> current_values(number, kMax);

    uint32_t index = 0;
    uint32_t value = 0;

    for (uint32_t i = 0; i < number_queries; ++i) {
        index = next() % number;
        value = next();

        if (value < cur_min) {
            cur_min = value;
        }
        
        uint32_t temp = current_values[index];
        current_values[index] = value;
        
        if (temp == cur_min) {
            cur_min = *std::min_element(current_values.begin(), current_values.end());
        }
    
        sum += cur_min * cur_power;
        cur_power *= kConst;
    }

    return sum;
}

int main() {
    uint32_t number = 0;
    uint32_t number_queries = 0;

    std::cin >> number >> number_queries >> x0 >> x1 >> a >> b >> c;

    std::cout << AskMin(number, number_queries) << '\n';

    return 0;
}
