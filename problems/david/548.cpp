#include <iostream>
#include <vector>
#include <sstream>

struct node {
    int data;
    node* left;
    node* right;

    node(int n) : data(n) {
        left = nullptr;
        right = nullptr;
    }
};

struct tree {
    node* root;

    tree(int n) {
        root = new node(n);
    }

    ~tree() {
        kill_tree(this->root);
    }

    void kill_tree(node* root) {
        kill_tree(root->left);
        kill_tree(root->right);
        delete root;
    }
};



int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss1(line);
        int tmp;
        std::vector<int> inorder;

        while (ss1 >> tmp)
            inorder.push_back(tmp);

        std::getline(std::cin, line);
        std::stringstream ss2(line);
        std::vector<int> postorder;

        while (ss2 >> tmp)
            postorder.push_back(tmp);


        std::vector<int> postorder;

        int tmp;
    }

    return 0;
}

