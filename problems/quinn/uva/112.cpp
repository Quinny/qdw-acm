#include <iostream>
#include <stack>

// because UVA input is awesome...
#define EMPTY_TREE -10001

struct node {
    int data;
    node* right, *left;
    node(int n = 0): data(n), right(nullptr), left(nullptr) {};
};

bool sum_exists(node* root, int left) {
    if (root == nullptr || root->data == EMPTY_TREE)
        return false;
    left -= root->data;
    if (root->left->data == EMPTY_TREE && root->right->data == EMPTY_TREE && left == 0)
        return true;
    return sum_exists(root->left, left) || sum_exists(root->right, left);
}

void kill(node* n) {
    if (n == nullptr)
        return;
    kill(n->left);
    kill(n->right);
    delete n;
}

node* parse_tree() {
    char c;
    int n;
    std::stack<node*> s;
    std::cin >> c >> n;

    if (!std::cin) {
        std::cin.clear();
        std::cin >> c;
        return nullptr;
    }
    s.push(new node(n));

    while (!s.empty()) {
        std::cin >> c;
        if (c == ')') {
            if (s.size() == 1)
                break;
            auto n2 = s.top();
            s.pop();
            auto n1 = s.top();
            s.pop();
            if (n1->left == nullptr)
                n1->left = n2;
            else
                n1->right = n2;
            s.push(n1);
        }
        else {
            std::cin >> n;
            if (!std::cin) {
                std::cin.clear();
                n = EMPTY_TREE;
            }
            s.push(new node(n));
        }
    }
    return s.top();
}

int main() {
    int sum_to;
    while (std::cin >> sum_to) {
        auto tree = parse_tree();
        auto check = sum_exists(tree, sum_to);
        if (tree == nullptr || !check)
            std::cout << "no" << std::endl;
        else
            std::cout << "yes" << std::endl;
        kill(tree);
    }
    return 0;
}
