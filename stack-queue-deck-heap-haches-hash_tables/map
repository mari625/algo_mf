#include <iostream>
#include <string>
#include <unordered_map>

void AllAccounts(int number) {
    std::unordered_map<std::string, int> accounts;
    accounts.reserve(number);
    const float kLoad = 0.25;
    accounts.max_load_factor(kLoad);

    for (int i = 0; i < number; ++i) {
        std::string query;
        std::getline(std::cin, query);
        std::string substring = query.substr(2);

        if (query[0] == '1') {
            int pos = substring.find(' ');
            std::string name = substring.substr(0, pos);
            int sum = std::stoi(substring.substr(pos));

            if (accounts.find(name) == accounts.end()) {
                accounts[name] = 0;
            }

            accounts[name] += sum;
        } else {
            std::string name = substring;

            if (accounts.find(name) == accounts.end()) {
                std::cout << "ERROR" <<'\n';
            } else {
                std::cout << accounts[name] << '\n';
            }
        }
    }
}

int main() {
    std::string number;

    std::getline(std::cin, number);

    AllAccounts(std::stoi(number));

    return 0;
}
