#include <iostream>
#include <vector>
#include <set>

struct Edge {
    int begin = 0;
    int end = 0;
    int number = 0;

    bool operator< (const Edge& other) const {
        return number < other.number;
    }
};

struct Categories {
    std::set<Edge> income;
    std::set<Edge> outcome;
};

void DFS(const std::vector<Categories>& graph, int vertex_number,
    std::vector<char>& colour, std::vector<int>& answer) {
    colour[vertex_number] = 'g';

    for (auto& edge : graph[vertex_number].outcome) {
        int new_vertex_number = edge.end;
        if (colour[new_vertex_number] == 'w') {
            DFS(graph, new_vertex_number, colour, answer);
        }
    }

    colour[vertex_number] = 'b';
    answer.push_back(vertex_number);
}

void FindCompany(std::vector<Categories>& graph, int vertex_number) {
    std::vector<char> colour(vertex_number, 'w');
    std::vector<int> answer;

    for (int i = 0; i < vertex_number; ++i) {
        if (colour[i] == 'w') {
            DFS(graph, i, colour, answer);
        }
    }

    int sink = answer[0];
    for (int i = 1; i < vertex_number; ++i) {
        if (graph[answer[i]].outcome.size() == 0) {
            std::cout << "-1" << '\n';
            return;
        }
    }

    int used = 1;
    std::vector<Edge> candidates;
    int max_number = 0;
    while (used != vertex_number) {
        for (auto& edge : graph[sink].income) {
            graph[edge.begin].outcome.erase(edge);
            if (graph[edge.begin].outcome.size() == 0) {
                candidates.push_back(edge);
            }
        }

        if (candidates.size() != 1) {
            std::cout << "-1" << '\n';
            return;
        } else {
            sink = candidates[0].begin;
            max_number = std::max(candidates[0].number, max_number);
            candidates.clear();
        }

        ++used;
    }

    std::cout << max_number << '\n';
}

int main() {
    int vertex_number = 0;
    int edge_number = 0;

    std::cin >> vertex_number >> edge_number;

    std::vector<Categories> graph(vertex_number);

    for (int i = 0; i < edge_number; ++i) {
        int first = 0;
        int second = 0;
        std::cin >> first >> second;

        graph[first - 1].outcome.insert(Edge{ first - 1, second - 1, i + 1 });
        graph[second - 1].income.insert(Edge{ first - 1, second - 1, i + 1 });
    }

    FindCompany(graph, vertex_number);

    return 0;
}
