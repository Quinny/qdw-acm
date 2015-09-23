#include <iostream>
#include <map>
#include <queue>

struct trie_node {
    bool word_end = false;
    std::map<char, trie_node*> children;
};

struct trie {
    trie_node* root;

    trie(): root(new trie_node()) {};

    void insert(const std::string& s) {
        auto cur = root;
        for (auto i: s) {
            auto check = cur->children.insert({i, nullptr});
            if (check.second)
                check.first->second = new trie_node();
            cur = cur->children[i];
        }
        cur->word_end = true;
    }

    void words() {
        std::queue<std::pair<std::string, trie_node*>> q;
        q.push({"", root});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.second->word_end)
                std::cout << t.first << std::endl;

            for (auto i: t.second->children)
                q.push({t.first + i.first, t.second->children[i.first]});
        }
    }

    std::vector<std::string> prefix_matches(std::string s) const {
        auto cur = root;
        std::vector<std::string> ret;
        std::string build;
        for (auto i: s) {
            if (cur->word_end)
                ret.push_back(build);
            if (cur->children.find(i) == cur->children.end())
                break;
            build += i;
            cur = cur->children[i];
        }
        if (s == build && cur->word_end)
            ret.push_back(s);
        return ret;
    }

    bool valid_word(const std::string& s) const {
        auto cur = root;
        for (auto i: s) {
            if (cur->word_end)
                return false;
            if (cur->children.find(i) == cur->children.end())
                return false;
            cur = cur->children[i];
        }
        return cur->word_end && cur->children.size() == 0;
    }    

    ~trie() {
        std::queue<trie_node*> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto i: t->children)
                q.push(i.second);
            delete t;
        }
    }
};


int main() {
    trie t;

    t.insert("hello");
    t.insert("world");
    return 0;
}
