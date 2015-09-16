#include <map>
#include <set>
#include <queue>
#include <iostream>

template <typename T>
struct directed_graph {
    std::map<T, std::set<T>> g_;
    std::map<T, std::size_t> incoming_count_;

    void connect(const T& u, const T& v) {
        incoming_count_.insert({u, 0});
        g_[u].insert(v);
        ++incoming_count_[v];
    }

    void disconnect(const T& u, const T& v) {
        g_[u].erase(v);
        --incoming_count_[v];
    }

    std::set<T> operator[] (const T& u) {
        return g_[u];
    }
};
