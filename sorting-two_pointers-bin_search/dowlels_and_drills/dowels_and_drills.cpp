#include <iostream>
#include <vector>

int FindMin(int number_d, std::vector<int>& deb, int number_s, std::vector<int>& sv) {
    int first_iterator = 0;
    int second_iterator = 0;
    const int kBig = 1'000'000'000;
    int min_dif = kBig;

    while (first_iterator < number_d && second_iterator < number_s) {
        while (first_iterator < number_d && deb[first_iterator] <= sv[second_iterator]) {
            int cur_dif = sv[second_iterator] - deb[first_iterator];
            if (min_dif > cur_dif) {
                min_dif = cur_dif;
            }

            first_iterator ++;
        }

        while (second_iterator < number_s && sv[second_iterator] <= deb[first_iterator]) {
            int cur_dif = deb[first_iterator] - sv[second_iterator];
            if (min_dif > cur_dif) {
                min_dif = cur_dif;
            }

            second_iterator ++;
        }
    }

    return min_dif;
}

int main() {
    int number_d = 0;
    int number_s = 0;

    std::cin >> number_d >> number_s;

    std::vector<int> deb(number_d);
    std::vector<int> sv(number_s);

    for (int i = 0; i < number_d; ++i) {
        std::cin >> deb[i];
    }

    for (int i = 0; i < number_s; ++i) {
        std::cin >> sv[i];
    }

    std::cout << FindMin(number_d, deb, number_s, sv) << '\n';
    return 0;
}
