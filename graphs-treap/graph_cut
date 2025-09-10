#include <iostream>
#include <vector>
#include <string>

struct Edge {
		int begin = 0;
		int end = 0;
		int weight = 0;
};

struct Task {
	Edge edge;
	char task;
};

struct DSU {
	DSU(int number) {
		prev.resize(number);

		for (int i = 0; i < number; ++i) {
			prev[i] = i;
		}

		size.resize(number);
	}

	int Get(int v) {
		return v == prev[v] ? v : prev[v] = Get(prev[v]);
	}

	void Unite(int v, int u) {
		v = Get(v);
		u = Get(u);

		if (v == u) {
			return;
		}

		if (size[v] > size[u]) {
			std::swap(v, u);
		}

		prev[v] = u;
		size[v] = size[u] + size[v];
	}

	std::vector<int> prev;
	std::vector<int> size;
};

void Complete(int number_vertices, int number_edges, const std::vector<Edge>& graph, int number_questions, const std::vector<Task>& tasks) {
	DSU dsu(number_vertices + 1);
	std::vector<char> answers;

	for (int i = number_questions - 1; i >= 0; --i) {
		if (tasks[i].task == 'a') {
			if (dsu.Get(tasks[i].edge.begin) == dsu.Get(tasks[i].edge.end)) {
				answers.push_back('y');
			}
			else {
				answers.push_back('n');
			}
		} else {
			dsu.Unite(tasks[i].edge.begin, tasks[i].edge.end);
		}
	}

	for (int i = static_cast<int>(answers.size()) - 1; i >= 0; --i) {
		if (answers[i] == 'y') {
			std::cout << "YES" << '\n';
		} else {
			std::cout << "NO" << '\n';
		}
	}
}

int main() {
	int number_vertices = 0;
	int number_edges = 0;
	int number_questions = 0;
	std::string str;

	std::getline(std::cin, str);

	number_vertices = std::stoi(str.substr(0, str.find(' ')));
	str = str.substr(str.find(' ') + 1);
	number_edges = std::stoi(str.substr(0, str.find(' ')));
	number_questions = std::stoi(str.substr(str.find(' ') + 1));

	std::vector<Edge> graph(number_edges);

	for (int i = 0; i < number_edges; ++i) {
		std::getline(std::cin, str);
		graph[i].begin = std::stoi(str.substr(0, str.find(' ')));
		graph[i].end = std::stoi(str.substr(str.find(' ') + 1));
	}

	std::vector<Task> tasks(number_questions);

	for (int i = 0; i < number_questions; ++i) {
		std::getline(std::cin, str);
		tasks[i].task = str[0];
		str = str.substr(str.find(' ') + 1);
		tasks[i].edge.begin = std::stoi(str.substr(0, str.find(' ')));
		tasks[i].edge.end = std::stoi(str.substr(str.find(' ') + 1));
	}

	Complete(number_vertices, number_edges, graph, number_questions, tasks);

	return 0;
}
