#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_set>

struct HashedVector {
    std::vector<std::vector<int64_t>> hashes;
    std::vector<std::vector<int64_t>> powers;
    int length;
    int max_power;
    const int64_t kM1 = 1'000'000'007;
    const int64_t kP1 = 1'000'003;
    const int64_t kM2 = 1'000'000'009;
    const int64_t kP2 = 1'000'033;

    HashedVector(const std::vector<int>& vec, int max) : max_power(max) {
        length = static_cast<int>(vec.size());

        powers.assign(max_power + 1, std::vector<int64_t>(2, 1));

        for (int i = 1; i <= max_power; ++i) {
            powers[i][0] = (powers[i - 1][0]*kP1) % kM1;
            powers[i][1] = (powers[i - 1][1]*kP2) % kM2;
        }

        hashes.assign(length, std::vector<int64_t>(2, 0));

        hashes[0][0] = (vec[0]*powers[vec[0] - 1][0]) % kM1;
        hashes[0][1] = (vec[0]*powers[vec[0] - 1][1]) % kM2;

        for (int i = 1; i < length; ++i) {
            hashes[i][0] = (hashes[i - 1][0] + vec[i]*powers[vec[i] - 1][0]) % kM1;
            hashes[i][1] = (hashes[i - 1][1] + vec[i]*powers[vec[i] - 1][1]) % kM2;
        }
    }

    std::vector<int64_t> GetHash(int left, int right) const {
        if (left == 0) {
            return hashes[right];
        }

        std::vector<int64_t> result(2,0);

        result[0] = (hashes[right][0] - hashes[left - 1][0]) % kM1;
        result[1] = (hashes[right][1] - hashes[left - 1][1]) % kM2;

        if (result[0] < 0) {
            result[0] += kM1;
        }

        if (result[1] < 0) {
            result[1] += kM2;
        }

        return result;
    }
};

struct CustomHash {
    int64_t operator() (const std::vector<int64_t>& vec) const {
        const int64_t kM = 1'000'000'087;
        const int64_t kP = 1'000'000'033;

        return (vec[0] + vec[1]*kP) % kM;
    }
};

bool Check(int length, std::unordered_set<std::vector<int64_t>, CustomHash>& hashes_from_first, int& answer, const HashedVector& first, const HashedVector& second) {
    hashes_from_first.clear();
 
    for (int i = 0; i < first.length - length + 1; ++i) {
        std::vector<int64_t> cur_hash = first.GetHash(i, i + length - 1);
 
        if (hashes_from_first.find(cur_hash) == hashes_from_first.end()) {
            hashes_from_first.insert(cur_hash);
        } 
    }

    for (int i = 0; i < second.length - length + 1; ++i) {
        std::vector<int64_t> cur_hash = second.GetHash(i, i + length - 1);

        auto pos = hashes_from_first.find(cur_hash);
        if (pos != hashes_from_first.end()) {
            if (*pos == cur_hash) {
                answer = length;
                return true;
            }
        }
    }

    return false;
}

int MaxAnagram(const std::vector<int>& first, const std::vector<int>& second, int first_max, int second_max) {
    HashedVector first_hashed = HashedVector(first, first_max);
    HashedVector second_hashed = HashedVector(second, second_max);

    std::unordered_set<std::vector<int64_t>, CustomHash> hashes_from_first; 
    int answer = 0;

    int left = 1;
    int right = std::min(first_hashed.length, second_hashed.length);
 
    for (int i = left; i <= right; ++i) {
        Check(i, hashes_from_first, answer, first_hashed, second_hashed);
    }
 
    return answer;
}

int main() {
    int first_len = 0;
    int second_len = 0;

    std::cin >> first_len;

    std::vector<int> first(first_len);

    int first_max = 0;

    for (int i = 0; i < first_len; ++i) {
        std::cin >> first[i];

        if (first[i] > first_max) {
            first_max = first[i];
        }
    }

    std::cin >> second_len;

    std::vector<int> second(second_len);

    int second_max = 0;

    for (int i = 0; i < second_len; ++i) {
        std::cin >> second[i];

        if (second[i] > second_max) {
            second_max = second[i];
        }
    }

    std::cout << MaxAnagram(first, second, first_max, second_max) << '\n';

    return 0;
}
