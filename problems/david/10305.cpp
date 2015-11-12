#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

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

    void insert(const T& u) {
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

    for (auto p : g.incoming_count_) {
        if (p.second == 0) {
            q.push(p.first);
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        ret.push_back(top);

        for (int v : g[top]) {
            g.disconnect(top, v);
            if (g.incoming_count_[v] == 0)
                q.push(v);
        }
    }

    return ret;
}

int main() {
    int n, m;

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        int task1, task2;
        directed_graph<int> g;

        for (int i = 1; i <= n; ++i) {
            g.insert(i);
        }

        for (int i = 0; i != m; ++i) {
            std::cin >> task1 >> task2;
            g.connect(task1, task2);
        }

        std::vector<int> v = toposort(g);

        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

