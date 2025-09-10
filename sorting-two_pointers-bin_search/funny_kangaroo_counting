#include <iostream>
#include <vector>
#include <algorithm>

int VisibleKangaroos(int number, std::vector<int>& kangaroos) {
    int invisible_number = 0;

    int first_iterator = number - 1;
    int second_iterator = (number - 1) / 2;

    while (first_iterator > (number - 1) / 2 && second_iterator >= 0) {
        if (kangaroos[first_iterator] >= kangaroos[second_iterator] * 2) {
            invisible_number ++;
            first_iterator --;
        }

        second_iterator --;
    }

    return number - invisible_number;
}

int main() {
    int number = 0;
    std::cin >> number;

    std::vector<int> kangaroos(number);

    for(int i = 0; i < number; ++i) {
        std::cin >> kangaroos[i];
    }

    std::sort(kangaroos.begin(), kangaroos.end());

    std::cout << VisibleKangaroos(number, kangaroos) << '\n';
    return 0;
}
