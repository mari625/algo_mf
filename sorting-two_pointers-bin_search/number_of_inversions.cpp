#include <cstdint>
#include <iostream>
#include <vector>
 
std::vector<int> Merge(int first_length, int second_length,
                       std::vector<int>& first_container,
                       std::vector<int>& second_container, uint64_t& number_of_inversions) {
 
    std::vector<int> result;
 
    int first_iterator = 0;
    int second_iterator = 0;
 
    while (first_iterator < first_length && second_iterator < second_length) {
        if (first_container[first_iterator] <
            second_container[second_iterator]) {
            result.push_back(first_container[first_iterator]);
            first_iterator += 1;
        } else {
            result.push_back(second_container[second_iterator]);
            second_iterator += 1;
            number_of_inversions += first_length - first_iterator;
        }
    }
 
    while (first_iterator < first_length) {
        result.push_back(first_container[first_iterator]);
        first_iterator += 1;
    }
    while (second_iterator < second_length) {
        result.push_back(second_container[second_iterator]);
        second_iterator += 1;
    }
 
    return result;
}
 
void TotalMerge(std::vector<int>& array, int number, uint64_t& number_of_inversions) {
    std::vector<std::vector<int>> large_container =
        std::vector<std::vector<int>>(number, std::vector<int>(1));
 
    for (int i = 0; i < number; ++i) {
        large_container[i][0] = array[i];
    }
 
    std::vector<std::vector<int>> little_container;
    int number_of_containers = number;
    int current_number = number_of_containers;
    int remained = 0;
    int length = 1;
 
    while (number_of_containers != 1) {
        current_number = number_of_containers + remained - 1;
        while (current_number > remained) {
            std::vector<int> merged =
                Merge(length, length, large_container[current_number - 1],
                      large_container[current_number], number_of_inversions);
            large_container.pop_back();
            large_container.pop_back();
            little_container.push_back(merged);
            current_number -= 2;
        }
 
        for (int i = std::ssize(little_container) - 1; i >= 0; --i) {
            large_container.push_back(little_container[i]);
        }
        little_container.clear();
 
        if (number_of_containers % 2 == 1) {
            remained += 1;
        }
        number_of_containers = number_of_containers / 2;
        length *= 2;
    }
 
    while (large_container.size() != 1) {
        std::vector<int> first_container =
            large_container[large_container.size() - 2];
        std::vector<int> second_container =
            large_container[large_container.size() - 1];
        std::vector<int> merged =
            Merge(first_container.size(), second_container.size(),
                  first_container, second_container, number_of_inversions);
        large_container.pop_back();
        large_container.pop_back();
        large_container.push_back(merged);
    }
}
 
int main() {
    int number = 0;
    std::cin >> number;
 
    std::vector<int> array(number);
 
    for (int i = 0; i < number; ++i) {
        std::cin >> array[i];
    }
 
    uint64_t number_of_inversions = 0;
    TotalMerge(array, number, number_of_inversions);

    std::cout<<number_of_inversions<<'\n';
 
    return 0;
}
