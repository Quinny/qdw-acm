#include <cstddef>
#include <vector>
#include <stack>

template <typename T>
struct segment_node {
    segment_node* left, *right;
    std::size_t to, from;
    T data;

    segment_node(std::size_t f, std::size_t t, T d = 0): to(t), from(f),
    left(nullptr), right(nullptr), data(d) {};
};

template <typename T>
struct segment_tree {
    segment_node<T>* root_;
    std::vector<T> orig_;

    segment_tree(): root_(nullptr) {};

    segment_tree(const std::vector<T>& v) {
        orig_ = v;
        std::stack<segment_node<T>*> s;
        for (std::size_t i = 0; i < v.size(); ++i)
            s.push(new segment_node<T>(i, i, v[i]));

        while (s.size() > 1) {
            auto n2 = s.top();
            s.pop();

            auto n1 = s.top();
            s.pop();

            auto n = new segment_node<T>(n1->from, n2->to, n1->data + n2->data);
            n->left = n1;
            n->right = n2;
            s.push(n);
        }
        root_ = s.top();
    }

    T sum_range(std::size_t start, std::size_t end) {
        return sum_range(root_, start, end);
    }

    T sum_range(segment_node<T>* cur, std::size_t start, std::size_t end) {
        if (cur == nullptr)
            return 0;
        if (cur->from >= start && cur->to <= end)
            return cur->data;
        if (cur->to < start || cur->from > end)
            return 0;
        return sum_range(cur->left, start, end) +
            sum_range(cur->right, start, end);
    }

    // updates index i to n and reflects changes
    void update(std::size_t i, T n) {
        T diff = n - orig_[i];
        update(root_, i, diff);
    }

    void update(segment_node<T>* root, std::size_t i, T diff) {
        if (root == nullptr)
            return;
        if (i >= root->from && i <= root->to)
            root->data += diff;
        update(root->left, i, diff);
        update(root->right, i, diff);
    }

    void kill(segment_node<T>* root) {
        if (root == nullptr)
            return;
        kill(root->left);
        kill(root->right);
        delete root;
    }

    ~segment_tree() {
        kill(root_);
    }
};
