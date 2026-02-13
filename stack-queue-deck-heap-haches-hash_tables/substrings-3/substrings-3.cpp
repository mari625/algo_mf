#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct HashedString {
    std::vector<int64_t> hashes;
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

        hashes.assign(length, 0);

        hashes[0] = str[0] - 'a' + 1;

        for (int i = 1; i < length; ++i) {
            hashes[i] = (hashes[i - 1]*kP + str[i] - 'a' + 1) % kM;
        }

    }

    int64_t GetHash(int left, int right) const {
        if (left == 0) {
            return hashes[right];
        }

        int64_t result = (hashes[right] - hashes[left - 1]*powers[right - left + 1]) % kM;

        if (result < 0) {
            result += kM;
        }

        return result;
    }
};

struct SubstrAppearances {
    std::string substring;
    int apperances;
};

bool Check(int substr_length, int number, const std::vector<HashedString>& strings, std::string& answer, std::unordered_map<int64_t, std::vector<SubstrAppearances>>& cur_hashes) {
    int pos = 1;
    int sum = pos;

    cur_hashes.clear();

    for (int i = 0; i < strings[0].length - substr_length + 1; ++i) {
        int64_t cur_hash = strings[0].GetHash(i, i + substr_length - 1);
        std::string cur_string = strings[0].string.substr(i, substr_length);

        if (cur_hashes.find(cur_hash) == cur_hashes.end()) {
            cur_hashes[cur_hash] = {{cur_string, pos}};
        } else {
            bool flag = false;

            for (int i = 0; i < std::ssize(cur_hashes[cur_hash]); ++i) {
                if (cur_hashes[cur_hash][i].substring == cur_string) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                cur_hashes[cur_hash].push_back({cur_string, pos});
            }
        }
    }

    for (int i = 1; i < number; ++i) {
        pos = pos << 1;
        sum += pos;

        for (int j = 0; j < strings[i].length - substr_length + 1; ++j) {
            int64_t cur_hash = strings[i].GetHash(j, j + substr_length - 1);
            std::string cur_string = strings[i].string.substr(j, substr_length);
    
            if (cur_hashes.find(cur_hash) != cur_hashes.end()) {
                for (int k = 0; k < std::ssize(cur_hashes[cur_hash]); ++k) {
                    if (cur_hashes[cur_hash][k].substring == cur_string) {
                        if ((cur_hashes[cur_hash][k].apperances >> i) % 2 == 0) {
                            cur_hashes[cur_hash][k].apperances += pos;
                        }
                        break;
                    }
                }
            }
        }
    }

    for (auto& item: cur_hashes) {
        for (auto& elem: item.second) {
            if (elem.apperances == sum) {
                answer = elem.substring;
                return true;
            }
        }
    }
    
    return false;
}

std::string FindSubString(int number, const std::vector<HashedString>& strings, int min_length) {
    int left = 0;
    int right = min_length;
    std::string answer;
    std::unordered_map<int64_t, std::vector<SubstrAppearances>> cur_hashes;

    while (left + 1 < right) {
        int middle = (left + right) / 2;

        if (Check(middle, number, strings, answer, cur_hashes)) {
            left = middle;
        } else {
            right = middle;
        }
    }

    Check(right, number, strings, answer, cur_hashes);

    return answer;
}

int main() {
    int number = 0;

    std::cin >> number;

    std::vector<HashedString> strings;

    int min_length = 0;;

    for (int i = 0; i < number; ++i) {
        std::string temp;
        std::cin >> temp;

        int length = static_cast<int>(temp.size());

        if (min_length == 0) {
            min_length = length;
        }

        if (length < min_length) {
            min_length = length;
        }

        strings.push_back(HashedString(temp));
    }

    std::cout << FindSubString(number, strings, min_length) << '\n';

    return 0;
}
