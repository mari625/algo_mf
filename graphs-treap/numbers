#include <iostream>
#include <vector>
#include <queue>

std::vector<int> BFS(int start, int end) {
	std::vector<char> visited(100'000, '0');
	std::vector<int> prev(100'000, 0);

	std::queue<int> neighbours;
	neighbours.push(start);

	std::vector<int> results(4, 0);

	while (!neighbours.empty()) {
		int cur = neighbours.front();
		neighbours.pop();

		if (cur == end) {
			break;
		}

		int first_digit = cur / 1000;
		int last_digit = cur % 10;

		if (first_digit!= 9) {
			results[0] = cur + 1000;
		} else {
			results[0] = 0;
		}
		if (last_digit != 1) {
			results[1] = cur - 1;
		} else {
			results[1] = 0;
		}
		results[2] = (cur % 1000) * 10 + first_digit;
		results[3] = (last_digit) * 1000 + cur / 10;

		for (int result : results) {
			if (result != 0 && visited[result] == '0') {
				neighbours.push(result);
				prev[result] = cur;
				visited[result] = '1';
			}
		}
	}

	std::vector<int> answer = { end };

	int cur = end;
	while (cur != start) {
		cur = prev[cur];
		answer.push_back(cur);
	}

	return answer;
}

int main() {
	int start = 0;
	int end = 0;

	std::cin >> start;
	std::cin >> end;

	std::vector<int> answer = BFS(start, end);

	for (int i = static_cast<int>(answer.size()) - 1; i >= 0; --i) {
		std::cout << answer[i] << '\n';
	}

	return 0;
}
