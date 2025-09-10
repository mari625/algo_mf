#include <cstdint>
#include <iostream>

uint64_t FindSquare(uint64_t width, uint64_t height, uint64_t number) {
    uint64_t left = 0;
    const uint64_t kBig = 100'000'000'000'000;
    uint64_t right = kBig;

    uint64_t middle = 0;
    while (left < right) {
        middle = (left + right) / 2;
        if ((middle / width) * (middle /
                height) < number) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}

int main() {
    uint64_t width = 0;
    uint64_t height = 0;
    uint64_t number = 0;

    std::cin >> width >> height >> number;

    std::cout << FindSquare(width, height, number) << '\n';
    return 0;
}
