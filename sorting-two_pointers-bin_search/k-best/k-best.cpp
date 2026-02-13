#include <iostream>
#include <vector>
#include <algorithm>

struct Diamond {
    double value = 0;
    double weight = 0;
    int number = 0;
    double mult = 0;

    bool operator==(Diamond other) const {
        return value - mult*weight == other.value - mult*other.weight;
    }

    bool operator<(Diamond other) const {
        return value - mult*weight > other.value - mult*other.weight;
    }
};

void Initiate(int number, std::vector<Diamond>& diamonds, double mult) {
    for (int i = 0; i < number; ++i) {
        diamonds[i].mult = mult;
    }

    std::sort(diamonds.begin(), diamonds.end());
}

bool EnoughDiamonds(int number, int k_number, std::vector<Diamond>& diamonds, double mult) {
    Initiate(number, diamonds, mult);

    double sum = 0;
    
    for (int i = 0; i < k_number; ++i) {
        sum += (diamonds[i].value - diamonds[i].weight*mult);
    }

    return sum >= 0;
}



void FindKBest(int number, int k_number, std::vector<Diamond>& diamonds) {
    const double kBig = 1e+7 + 1;
    const double kEps = 1e-9;
    double left = 0;
    double right = kBig;
    double middle = 0;

    while (left + kEps < right) {
        middle = (left + right) / 2;
        if (EnoughDiamonds(number, k_number, diamonds, middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }

    Initiate(number, diamonds, left);

    for (int i = 0; i < k_number; ++i) {
        std::cout << diamonds[i].number << '\n';
    }
}

int main() {
    int number = 0;
    int k_number = 0;

    std::cin >>  number >> k_number;

    std::vector<Diamond> diamonds(number);

    for (int i = 0; i < number; ++i) {
        std::cin >> diamonds[i].value >> diamonds[i].weight;
        diamonds[i].number = i + 1;
    }

    FindKBest(number, k_number, diamonds);

    return 0;
}
