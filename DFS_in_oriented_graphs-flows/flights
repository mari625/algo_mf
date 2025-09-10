#include <iostream>
#include <vector>

struct Edge {
    int begin;
    int end;
    int weight;
};

struct Categories {
    std::vector<Edge> income;
    std::vector<Edge> outcome;
};

void DFS(std::vector<Categories>& graph, int vertex_number,
    std::vector<char>& colour, std::vector<int>& answer, int middle) {
    colour[vertex_number] = 'g';

    for (Edge& edge : graph[vertex_number].outcome) {
        int new_vertex_number = edge.end;
        if (colour[new_vertex_number] == 'w' && edge.weight <= middle) {
            DFS(graph, new_vertex_number, colour, answer, middle);
        }
    }

    colour[vertex_number] = 'b';
    answer.push_back(vertex_number);
}

void SFD(std::vector<Categories>& graph, int vertex_number,
    std::vector<char>& colour, int middle) {
    colour[vertex_number] = 'g';

    for (Edge& edge : graph[vertex_number].income) {
        int new_vertex_number = edge.end;
        if (colour[new_vertex_number] == 'w' && edge.weight <= middle) {
            SFD(graph, new_vertex_number, colour, middle);
        }
    }

    colour[vertex_number] = 'b';
}

bool IsConnected(std::vector<Categories>& graph, int vertex_number, int middle) {
    std::vector<char> colour(vertex_number, 'w');
    std::vector<int> answer;

    for (int i = 0; i < vertex_number; ++i) {
        if (colour[i] == 'w') {
            DFS(graph, i, colour, answer, middle);
        }
    }

    colour.assign(vertex_number, 'w');

    bool component_found = false;


    for (int i = vertex_number - 1; i >= 0; --i) {
        if (colour[answer[i]] == 'w') {
            if (component_found) {
                return false;
            }

            SFD(graph, answer[i], colour, middle);

            component_found = true;
        }
    }

    return true;
}

void FindWeight(std::vector<Categories>& graph, int vertex_number) {
    int left = -1;
    int right = 1e9;
    int middle = 0;

    if (vertex_number == 1) {
        std::cout << "0" << '\n';
        return;
    }

    while (left + 1 < right) {
        middle = (left + right) / 2;
        if (!IsConnected(graph, vertex_number, middle)) {
            left = middle;
        }  else {
            right = middle;
        }
    }

    std::cout << right << '\n';
}

int main() {
    int vertex_number = 0;
    std::cin >> vertex_number;

    std::vector<Categories> graph(vertex_number);

    int weight = 0;
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            std::cin >> weight;
            if (i == j) {
                continue;
            }

            graph[i].outcome.push_back(Edge{ i, j, weight });
            graph[j].income.push_back(Edge{ j, i, weight });
        }
    }

    FindWeight(graph, vertex_number);

    return 0;
}
