#include <iostream>
#include <map>

struct trie_node {
    std::size_t c;
    std::map<char, trie_node*> children;

    trie_node(): c{0} {};
};

struct trie {
    trie_node* root_;

    trie(): root_{new trie_node()} {};

    std::size_t insert(std::string s) {
        s += '$';
        auto cur = root_;
        std::size_t ret = 0;
        for (auto i: s) {
            ret += cur->c;
            auto check = cur->children.insert({i, nullptr});
            if (check.second)
                check.first->second = new trie_node();
            else
                ++ret;
            ++cur->c;
            cur = cur->children[i];
        }
        return ret;
    }
};

int main() {
    int n;
    int c = 1;
    while (std::cin >> n) {
        if (n == 0)
            break;

        std::size_t ret = 0;
        trie t;
        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            ret += t.insert(s);
        }

        std::cout << "Case " << c << ": " << ret << std::endl;
        ++c;
    }
    return 0;
}
