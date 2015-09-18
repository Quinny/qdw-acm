#include <iostream>
#include "directed_graph.h"
#include <vector>

// topological sort on a directed acyclic graph
std::vector<int> toposort(directed_graph<int> g) {
    std::vector<int> order;
    std::queue<int> q;
    // find all nodes with no incoming edges
    for (auto i: g.incoming_count_) {
        if (i.second == 0)
            q.push(i.first);
    }

    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        order.push_back(top);
        for (auto i: g[top]) {
            // remove the edge from u to v
            g.disconnect(top, i);
            // if v has no incoming edges, then its dependanices
            // have all been processed
            if (g.incoming_count_[i] == 0)
                q.push(i);
        }
    }
    return order;
}

int main() {
    directed_graph<int> g;
    int u, v;
    while (std::cin >> u >> v)
        g.connect(u, v);
    auto o = toposort(g);
    for (auto i : o)
        std::cout << i << " ";
    std::cout << std::endl;
}
