#include <iostream>
#include <vector>
#include <algorithm>

const int kBig = 1e9 + 7;

struct Node {
    int value = 0;
    int priority = 0;
    int true_priority = 0;
    int pos = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    int min = kBig;
    int min_pos = 0;
    int size = 1;

    Node(int value_, int priority_, int pos_) : value(value_), min(priority_), true_priority(priority_), min_pos(pos_), pos(pos_) {
        priority = rand();
    }
};

int GetMin(Node* v) {
    if (v == nullptr) {
        return kBig;
    }
    return v->min;
}

int GetMinPos(Node* v) {
    if (v == nullptr) {
        return -1;
    }
    return v->min_pos;
}

int GetValue(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->value;
}

int GetSize(Node* v) {
    if (v == nullptr) {
        return 0;
    }
    return v->size;
}

void RenewMinPos(Node* v) {
    if (v == nullptr) {
        return;
    }

    int left = GetMin(v->left);
    int right = GetMin(v->right);
    int cur = v->true_priority;

    int min = std::min(std::min(left, right), cur);
    v->min = min;

    if (min == left) {
        v->min_pos = GetMinPos(v->left);
    }
    else if (min == right) {
        v->min_pos = GetMinPos(v->right);
    }
    else {
        v->min_pos = v->pos;
    }
}

void RenewSize(Node* v) {
    if (v == nullptr) {
        return;
    }
    v->size = GetSize(v->left) + 1 + GetSize(v->right);
}

std::pair<Node*, Node*> Split(Node* v, int number) {
    std::pair<Node*, Node*> result;
    if (v == nullptr) {
        result = { nullptr, nullptr };
    }
    else if (GetSize(v->left) + 1 <= number) {
        result = Split(v->right, number - GetSize(v->left) - 1);
        v->right = result.first;
        result.first = v;
    }
    else {
        result = Split(v->left, number);
        v->left = result.second;
        result.second = v;
    }

    RenewMinPos(result.first);
    RenewMinPos(result.second);

    RenewSize(result.first);
    RenewSize(result.second);

    return result;
}

Node* Merge(Node* v_1, Node* v_2) {
    Node* result;
    if (v_1 == nullptr) {
        result = v_2;
    }
    else if (v_2 == nullptr) {
        result = v_1;
    }
    else if (v_1->priority < v_2->priority) {
        v_1->right = Merge(v_1->right, v_2);
        result = v_1;
    }
    else {
        v_2->left = Merge(v_1, v_2->left);
        result = v_2;
    }

    RenewMinPos(result);
    RenewSize(result);

    return result;
}

int MinPos(Node* root, int left, int right) {
    std::pair<Node*, Node*> split_result_first = Split(root, left);
    std::pair<Node*, Node*> split_result_second = Split(split_result_first.second, right - left + 1);

    int min = GetMinPos(split_result_second.first);

    root = Merge(split_result_second.first, split_result_second.second);
    root = Merge(split_result_first.first, root);

    return min;
}

struct Element {
    int number = 0;
    int key = 0;
    int priority = 0;

    bool operator==(const Element& other) const {
        return number == other.number && key == other.key && priority == other.priority;
    }

    bool operator<(const Element& other) const {
        return key < other.key;
    }
};

struct NodeInfo {
    int number = 0;
    int prev = 0;
    int left = 0;
    int right = 0;

    bool operator==(const NodeInfo& other) const {
        return number == other.number && prev == other.prev && left == other.left && right == other.right;
    }

    bool operator<(const NodeInfo& other) const {
        return number < other.number;
    }
};

int BuildTree(Node* root, int begin, int end, std::vector<NodeInfo>& answer, int prev, const std::vector<int>& numbers) {
    NodeInfo node;
    if (begin > end) {
        return 0;
    }

    int position = MinPos(root, begin, end);
    node.number = numbers[position];
    node.prev = prev;

    node.left = BuildTree(root, begin, position - 1, answer, node.number, numbers);
    node.right = BuildTree(root, position + 1, end, answer, node.number, numbers);

    answer.push_back(node);

    return node.number;
}

void FindTree(int number, const std::vector<Element>& elements) {
    Node* root = nullptr;
    std::vector<int> numbers(number);

    for (int i = 0; i < number; ++i) {
        root = Merge(root, new Node{ elements[i].key, elements[i].priority, i });
        numbers[i] = elements[i].number;
    }


    std::vector<NodeInfo> answer;

    BuildTree(root, 0, number - 1, answer, 0, numbers);

    std::sort(answer.begin(), answer.end());

    std::cout << "YES" << '\n';
    for (int i = 0; i < number; ++i) {
        std::cout << answer[i].prev << " " << answer[i].left << " " << answer[i].right << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int number = 0;

    std::cin >> number;

    std::vector<Element> elements(number);
    for (int i = 0; i < number; ++i) {
        elements[i].number = i + 1;
        std::cin >> elements[i].key >> elements[i].priority;
    }

    std::sort(elements.begin(), elements.end());

    FindTree(number, elements);

    return 0;
}
