#include <iostream>
#include <queue>
#include <deque>

void Organize(int number) {
    std::queue<int> first_queue;
    std::deque<int> second_queue;

    for (int i = 0; i < number; ++i) {
        std::string query;
        std::getline (std::cin, query);

        if (query[0] == '+') {
            second_queue.push_back(std::stoi(query.substr(1)));

            if (first_queue.size() < second_queue.size()) {
                first_queue.push(second_queue.front());
                second_queue.pop_front();
            }
        } else if (query[0] == '*') {
            if (first_queue.size() == second_queue.size()) {
                first_queue.push(std::stoi(query.substr(2)));
            } else {
                second_queue.push_front(std::stoi(query.substr(2)));
            }
        } else {
            std::cout << first_queue.front() << '\n';
            first_queue.pop();

            if (first_queue.size() < second_queue.size()) {
                first_queue.push(second_queue.front());
                second_queue.pop_front();
            }
        }
    }
}

int main() {
    std::string number;

    std::getline(std::cin, number);

    Organize(std::stoi(number));
    return 0;
}
