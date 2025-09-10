#include <iostream>
#include <string>

struct Node {
    int value = 0;
    int priority = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    size_t size = 1;

    Node(int value_) : value(value_) {
        priority = rand();
    }
};

size_t GetSize(Node* v) {
    if (!v) {
        return 0;
    }
    return v->size;
}

int GetValue(Node* v) {
    if (!v) {
        return 0;
    }
    return v->value;
}

void RenewSize(Node* v) {
    if (!v) {
        return;
    }
    v->size = GetSize(v->left) + 1 + GetSize(v->right);
}

std::pair<Node*, Node*> Split(Node* v, int value) {
    std::pair<Node*, Node*> result;
    if (!v) {
        result = { nullptr, nullptr };
    }
    else if (GetValue(v) <= value) {
        result = Split(v->right, value);
        v->right = result.first;
        result.first = v;
    }
    else {
        result = Split(v->left, value);
        v->left = result.second;
        result.second = v;
    }

    RenewSize(result.first);
    RenewSize(result.second);

    return result;
}

Node* Merge(Node* v_1, Node* v_2) {
    Node* result;
    if (!v_1) {
        result = v_2;
    } else if (!v_2) {
        result = v_1;
    } else if (v_1->priority < v_2->priority) {
        v_1->right = Merge(v_1->right, v_2);
        result = v_1;
    } else {
        v_2->left = Merge(v_1, v_2->left);
        result = v_2;
    }

    RenewSize(result);
    return result;
}

int Find(Node* v, int position) {
    int result = 0;
    if (GetSize(v->left) + 1 > position) {
        result = Find(v->left, position);
    } else if (GetSize(v->left) + 1 == position) {
        result = GetValue(v);
    } else {
        result = Find(v->right, position - GetSize(v->left) - 1);
    }
    return result;
}

int main() {
    int number = 0;
    std::string str;

    std::getline(std::cin, str);
    number = std::stoi(str);

    Node* root = nullptr;

    for (int i = 0; i < number; ++i) {
        std::getline(std::cin, str);

        int number = std::stoi(str.substr(2));
        if (str[0] == '1') {
            std::pair<Node*, Node*> split_result = Split(root, number);
            root = Merge(split_result.first, new Node {number} );
            root = Merge(root, split_result.second);
        } else if (str[0] == '0') {
            std::cout << Find(root, GetSize(root) + 1 - number) << '\n';
        } else {
            std::pair<Node*, Node*> split_1 = Split(root, number - 1);
            std::pair<Node*, Node*> split_2 = Split(split_1.second, number);
            root = Merge(split_1.first, split_2.second);
        }
    }

    return 0;
}
