#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

struct Log {
    int train;
    int place;
};

void CheckSchedule(int number) {
    std::unordered_map<int, int> positions;
    std::priority_queue<int, std::vector<int>, std::greater<int>> free;
    std::vector<Log> logs;

    for (int i = 1; i <= number; ++i) {
        free.push(i);
    }

    while (true) {
        std::string query;
        std::getline(std::cin, query);

        if (query.empty()) {
            break;
        }

        int elem = std::stoi(query.substr(2));

        if (query[0] == '+') {
            if (free.empty()) {
                std::cout << 0 << " " << elem << '\n';
                return;
            }

            logs.push_back(Log{elem, free.top()});

            positions[elem] = free.top();
            free.pop();
        } else {
            free.push(positions[elem]);
            positions.erase(elem);
        }
    }

    for (auto& log: logs) {
        std::cout << log.train << " " << log.place << '\n';
    }

}

int main() {
    std::string number;

    std::getline(std::cin, number);

    CheckSchedule(std::stoi(number));

    return 0;
}
