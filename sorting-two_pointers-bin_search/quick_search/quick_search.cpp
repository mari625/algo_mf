#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int number = 0;
    std::cin >> number;

    std::vector<int> array(number);

    for (int i = 0; i < number; ++i) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());

    int number_of_queries = 0;
    std::cin >> number_of_queries;

    for (int i = 0; i < number_of_queries; ++i) {
        int left = 0;
        int right = 0;

        std::cin >> left >> right;

        std::cout << std::upper_bound(array.begin(), array.end(), right) - std::lower_bound(array.begin(), array.end(), left) << " ";
    }
    
    std::cout<<'\n';

    return 0;
}
