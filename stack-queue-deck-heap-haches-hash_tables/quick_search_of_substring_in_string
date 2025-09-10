#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
 
struct HashedString {
    std::vector<int64_t> hashes;
    std::vector<int64_t> powers;
    int length;
    int64_t m_parameter;
    int64_t p_parameter;
 
    HashedString(const std::string& str, int64_t m_param, int64_t p_param) : m_parameter(m_param), p_parameter(p_param) {
 
        length = static_cast<int>(str.size());
 
        powers.assign(length + 1, 1);
 
        for (int i = 1; i <= length; ++i) {
            powers[i] = (powers[i - 1]*p_parameter) % m_parameter;
        }
 
        hashes.assign(length, 0);
 
        hashes[0] = str[0] - 'A' + 1;
 
        for (int i = 1; i < length; ++i) {
            hashes[i] = (hashes[i - 1]*p_parameter + str[i] - 'A' + 1) % m_parameter;
        }
 
    }
 
    int64_t GetHash(int left, int right) const {
        if (left == 0) {
            return hashes[right];
        }
 
        int64_t result = (hashes[right] - hashes[left - 1]*powers[right - left + 1]) % m_parameter;
 
        if (result < 0) {
            result += m_parameter;
        }
 
        return result;
    }
};
 
int64_t HashString(const std::string& str, int64_t m_parameter, int64_t p_parameter) {
    int64_t hash = str[0] - 'A' + 1;
 
    for (int i = 1; i < static_cast<int>(str.size()); ++i) {
        hash = (hash*p_parameter + str[i] - 'A' + 1) % m_parameter;
    }
 
    return hash;
}
 
void CountSubString(const std::string& first, const std::string& second) {
    int counter = 0;
    std::vector<int> positions;
    positions.reserve(second.size());
 
    const int64_t kM = 1'000'000'007;
    const int64_t kP = 83;
 
    HashedString hashed_string = HashedString{second, kM, kP};
    int64_t substring_hash = HashString(first, kM, kP);
 
    int first_len = static_cast<int>(first.size());
    int second_len = static_cast<int>(second.size());
 
    for (int i = 0; i < second_len - first_len + 1; ++i) {
        int64_t cur_hash = hashed_string.GetHash(i, i + first_len - 1);
 
        if (cur_hash == substring_hash) {
            std::string cur_string = second.substr(i, first_len);

            if (cur_string == first) {
                counter += 1;
                positions.push_back(i + 1);
            }
        }
    }
 
    std::cout << counter << '\n';
 
    for (int i = 0; i < std::ssize(positions); ++i) {
        std::cout << positions[i] << " ";
    }
    std::cout << '\n';
}
 
int main() {
    std::string first;
    std::string second;
 
    std::cin >> first;
    std::cin >> second;
 
    CountSubString(first, second);
 
    return 0;
}
