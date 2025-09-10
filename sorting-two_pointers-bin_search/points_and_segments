#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int x = 0;
    bool begin = true;
    int number = 0;

    bool operator< (Event other) const {
        if (x == other.x && begin == other.begin) {
            return number < other.number;
        }
        if (x == other.x) {
            return begin;
        }
        return x < other.x;
    }

    bool operator== (Event other) const {
        return x == other.x && begin == other.begin && number == other.number;
    }
};

void PrecomputeEvents(std::vector<Event>& events, int number_of_segments) {
    std::sort(events.begin(), events.end());

    events[0].number = 1;
    for (int i = 1; i < number_of_segments*2; ++i) {
        if (events[i].begin) {
            events[i].number = events[i - 1].number + 1;
        } else {
            events[i].number = events[i - 1].number - 1;
        }
    }
}

int FindNumber(int dot, int number_of_events, std::vector<Event>& events) {
    auto lower_closed = std::lower_bound(events.begin(), events.end(), Event{dot, false, -1});
    if (lower_closed != events.begin()) {
        return (--lower_closed)->number;
    }
    return 0;
}

int main() {
    int number_of_segments = 0;
    int number_of_dots = 0;

    std::cin >> number_of_segments >> number_of_dots;

    std::vector<Event> events(number_of_segments*2);

    for (int i = 0; i < number_of_segments; ++i) {
        int first = 0;
        int second = 0;
        std::cin >> first >> second;
        events[i].x = std::min(first, second);
        events[i].begin = true;
        events[i + number_of_segments].x = std::max(first, second);
        events[i + number_of_segments].begin = false;
    }

    PrecomputeEvents(events, number_of_segments);

    for (int i = 0; i < number_of_dots; ++i) {
        int dot = 0;
        std::cin >> dot;

        std::cout << FindNumber(dot, number_of_segments*2, events) <<" ";
    }
    std::cout<<'\n';

    return 0;
}
