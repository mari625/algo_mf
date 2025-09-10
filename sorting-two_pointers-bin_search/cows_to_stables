#include <iostream>
#include <vector>

int FindCowNumber(int distance, std::vector<int>& coordinates, int number) {
    int cow_number = 1;
    int iterator = 0;

    int pred_pos = 0;

    while (iterator < number) {
        if (coordinates[iterator] - coordinates[pred_pos] >= distance) {
            pred_pos = iterator;
            cow_number ++;
        }
        iterator ++;
    }

    return cow_number;
}

int FindDistance(int number, int cow_number, std::vector<int>& coordinates) {
    int left = 0;
    int right = coordinates[number - 1] - coordinates[0] + 1;
    int middle = 0;

    while (left + 1 < right) {
        middle = (left + right) / 2;
        if (FindCowNumber(middle, coordinates, number) >= cow_number) {
            left = middle;
        } else {
            right = middle;
        }
    }

    return left;
}

int main() {
    int number = 0;
    int cow_number = 0;

    std::cin >> number >> cow_number;

    std::vector<int> coordinates(number);

    for (int i = 0; i < number; ++i) {
        std::cin >> coordinates[i];
    }

    std::cout << FindDistance(number, cow_number, coordinates) <<'\n';

    return 0;
}
