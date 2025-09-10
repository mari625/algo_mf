#include <iostream>
#include <vector>

struct MarkedString {
    char letter;
    bool marker = true;
};

void DeleteFromString(std::vector<MarkedString>& m_from, std::vector<int>& permutation, int middle) {
    for (int i = 0; i <= middle; ++i) {
        m_from[permutation[i]].marker = false;
    }
}

void UpdateString(std::vector<MarkedString>& m_from) {
    for (int i = 0; i < std::ssize(m_from); ++i) {
        m_from[i].marker = true;
    }
}

bool CheckNumber(std::vector<MarkedString>& m_from, std::string& to, std::vector<int>& permutation, int middle) {
    DeleteFromString(m_from, permutation, middle);

    int first_iterator = 0;
    int second_iterator = 0;

    while (first_iterator < std::ssize(m_from)) {
        if (m_from[first_iterator].letter == to[second_iterator] && m_from[first_iterator].marker) {
            second_iterator ++;

            if(second_iterator == std::size(to)) {
                UpdateString(m_from);
                return true;
            }
        }
        first_iterator++;
    }

    UpdateString(m_from);
    return false;
}

int FindNumber(std::string& from, std::string& to, std::vector<int>& permutation) {
    std::vector<MarkedString> m_from(static_cast<int>(permutation.size()));

    for (int i = 0; i < std::ssize(permutation); ++i) {
        m_from[i].letter = from[i];
    }

    int left = 0;
    int right = static_cast<int>(permutation.size());
    int middle = 0;

    while (left< right) {
        middle = (left + right) / 2;
        if (CheckNumber(m_from, to, permutation, middle)) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}

int main() {
    std::string from;
    std::string to;

    std::cin >> from;
    std::cin >> to;

    std::vector<int> permutation(static_cast<int>(from.size()));

    for (int i = 0; i < std::size(from); ++i) {
        std::cin >> permutation[i];
        permutation[i] -- ;
    }

    std::cout << FindNumber(from, to, permutation) << '\n';
    return 0;
}
