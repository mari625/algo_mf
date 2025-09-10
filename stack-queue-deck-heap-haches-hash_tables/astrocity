#include <iostream>
#include <unordered_map>
#include <deque>

void SimulateQueue(int number) {
    std::unordered_map<int, int> id_with_time;
    std::deque<int> queue;

    int global_time = 0;

    for (int i = 0; i < number; ++i) {
        std::string query;
        std::getline(std::cin, query);

        if (query[0] == '1') {
            int id = std::stoi(query.substr(2));
            queue.push_back(id);
            id_with_time[id] = global_time;

            global_time += 1;
        } else if (query[0] == '2') {
            id_with_time.erase(queue.front());
            queue.pop_front();
        } else if (query[0] == '3') {
            id_with_time.erase(queue.back());
            queue.pop_back();

            global_time -= 1;
        } else if (query[0] == '4') {
            int id = std::stoi(query.substr(2));

            std::cout << id_with_time[id] - id_with_time[queue.front()] << '\n';
        } else {
            std::cout << queue.front() << '\n';
        }
    }
}

int main() {
    std::string number;

    std::getline(std::cin, number);

    SimulateQueue(std::stoi(number));

    return 0;
}
