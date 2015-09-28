#include <iostream>
#include "../../graphs/directed_graph.h"
#include <set>
#include <queue>

// a graph a euler cycle if it is connected and the degrees
// of all nodes are even

bool is_connected(directed_graph<int> g, std::size_t nodes) {
    std::queue<int> q;
    std::set<int> visited;

    auto first = g.g_.begin()->first;
    q.push(first);
    visited.insert(first);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (auto i: g[t]) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
    return visited.size() == nodes;
}

bool degree_requirements(std::map<int, int> counts) {
    for (auto i: counts)
        if (i.second % 2 == 1)
            return false;
    return true;
}

bool has_euler_cycle(std::map<int, int> counts, directed_graph<int> g, int nodes) {
    return degree_requirements(counts) && is_connected(g, nodes);
}

int main() {
    std::size_t nodes, edges;
    while (std::cin >> nodes >> edges) {
        std::map<int, int> counts;
        directed_graph<int> g;
        for (std::size_t i = 0; i < edges; ++i) {
            int n1, n2;
            std::cin >> n1 >> n2;
            ++counts[n1]; ++counts[n2];
            g.connect(n1, n2);
            g.connect(n2, n1);
        }
        auto check = has_euler_cycle(counts, g, counts.size());
        if (check)
            std::cout << "Possible";
        else
            std::cout << "Not Possible";
        std::cout << std::endl;
    }
    return 0;
}
