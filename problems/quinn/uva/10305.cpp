#include <map>
#include <set>
#include <queue>
#include <iostream>

// A directed graph implementation for contest use
// Members are intentionally left public for ease of use in
// contest style programming

template <typename T>
struct directed_graph {
    // maps vertex to set of neighbour nodes
    std::map<T, std::set<T>> g_;
    // keeps track of the number of incoming edges for a given vertex
    // useful for topological sort
    std::map<T, std::size_t> incoming_count_;

    void connect(const T& u, const T& v) {
        // insure each vertex is represented in the incoming map
        incoming_count_.insert({u, 0});
        g_[u].insert(v);
        ++incoming_count_[v];
    }

    void add(const T& u) {
        incoming_count_.insert({u, 0});
    }

    void disconnect(const T& u, const T& v) {
        g_[u].erase(v);
        --incoming_count_[v];
    }

    std::set<T> operator[] (const T& u) {
        return g_[u];
    }
};

std::vector<int> toposort(directed_graph<int> g) {
    std::queue<int> q;
    std::vector<int> ret;

    for (auto i: g.incoming_count_) {
        if (i.second == 0)
            q.push(i.first);
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ret.push_back(t);

        for (auto i: g[t]) {
           g.disconnect(t, i);
           if (g.incoming_count_[i] == 0)
               q.push(i);
        }
    }
    return ret;
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        directed_graph<int> g;
        for (int i = 1; i <= n; ++i)
            g.add(i);
        for (int i = 0; i < m; ++i) {
            int a, b;
            std::cin >> a >> b;
            g.connect(a, b);
        }
        auto x = toposort(g);
        for (auto i: x) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
