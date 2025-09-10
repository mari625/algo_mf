#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct HashedString {
    std::vector<int64_t> forward_hashes;
    std::vector<int64_t> backward_hashes;
    std::vector<int64_t> powers;
    std::string string;
    int length;
    const int64_t kM = 1'000'000'007;
    const int64_t kP = 53;

    HashedString(const std::string& str) : string(str) {

        length = static_cast<int>(str.size());

        powers.assign(length + 1, 1);

        for (int i = 1; i <= length; ++i) {
            powers[i] = (powers[i - 1]*kP) % kM;
        }

        forward_hashes.assign(length, 0);

        forward_hashes[0] = str[0] - 'a' + 1;

        for (int i = 1; i < length; ++i) {
            forward_hashes[i] = (forward_hashes[i - 1] + (str[i] - 'a' + 1)*powers[i]) % kM;
        }

        backward_hashes.assign(length, 0);

        backward_hashes[0] = str[0] - 'a' + 1;

        for (int i = 1; i < length; ++i) {
            backward_hashes[i] = (backward_hashes[i - 1]*kP + str[i] - 'a' + 1) % kM;
        }

    }

    int64_t GetForwardHash(int left, int right) const {
        if (left == 0) {
            return (forward_hashes[right]*powers[length - right]) % kM;
        }
        int64_t result = ((forward_hashes[right] - forward_hashes[left - 1])*powers[length - right]) % kM;
        
        if (result < 0) {
            result += kM;
        }

        return result;
    }

    int64_t GetBackwardHash(int left, int right) const {
        if (left == 0) {
            return (backward_hashes[right] * powers[length - right]) % kM;
        }

        int64_t result = (((backward_hashes[right] - backward_hashes[left - 1]*powers[right - left + 1]) % kM) * powers[length - right + left]) % kM;

        if (result < 0) {
            result += kM;
        }

        return result;
    }
};

bool IsEvenPalindrom(const HashedString& str, int len, int pos) {
    return str.GetForwardHash(pos + 1, pos + len) == str.GetBackwardHash(pos - len, pos - 1);
}

int64_t EvenPalindroms(const HashedString& str) {
    int64_t sum = 0;

    for (int i = 0; i < str.length; ++i) {
        int left = 1;
        int right = std::min(i, str.length - i - 1);

        if (right == 0) {
            continue;
        }

        while (left + 1 < right) {
            int middle = (left + right) / 2;

            if (IsEvenPalindrom(str, middle, i)) {
                left = middle;
            } else {
                right = middle;
            }
        }

        if (IsEvenPalindrom(str, right, i)) {
            sum += right;
        } else if (IsEvenPalindrom(str, left, i)) {
            sum += left;
        }

    }

    return sum;
}

bool IsOddPalindrom(const HashedString& str, int len, int pos) {
    if (pos - len < 0 || pos + len + 1 >= str.length) {
        return false;
    }

    return str.GetForwardHash(pos + 1, pos + len + 1) == str.GetBackwardHash(pos - len, pos);
}

int64_t OddPalindroms(const HashedString& str) {
    int64_t sum = 0;

    for (int i = 0; i < str.length - 1; ++i) {
        int left = 0;
        int right = std::min(i, str.length - i - 2);

        while (left + 1 < right) {
            int middle = (left + right) / 2;

            if (IsOddPalindrom(str, middle, i)) {
                left = middle;
            } else {
                right = middle;
            }
        }

        if (IsOddPalindrom(str, right, i)) {
            sum += right + 1;
        } else if (IsOddPalindrom(str, left, i)) {
            sum += left + 1;
        }

    }
    return sum;
}

int64_t CountPalindromes(const std::string& str) {
    HashedString hashed = HashedString(str);

    return EvenPalindroms(hashed) + OddPalindroms(hashed);
}

int main() {
    std::string str;

    std::cin >> str;

    std::cout << CountPalindromes(str) << '\n';

    return 0;
}
