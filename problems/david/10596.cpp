#include <iostream>
#include "../../graphs/directed_graph.h"
#include <set>
#include <queue>

bool is_connected(directed_graph<int> g, size_t nodes) {
    int start = g.g_.begin()->first;  // Dat data abstraction
    std::set<int> visited;
    std::queue<int> q;

    q.push(start);
    visited.insert(start);

    // Visit every connected node with BFS
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto i : g[cur]) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return nodes == visited.size();
}

bool valid_degree(std::map<int, int> degrees) {
    for (auto i : degrees) {
        if (i.second % 2 != 0) {
            return false;
        }
    }
    return true;
}

bool eulerian_cycle(directed_graph<int> g, std::map<int, int> degrees) {
    return is_connected(g, g.g_.size()) && valid_degree(degrees);
}

int main() {
    int n, e;

    while (std::cin >> n >> e) {
        directed_graph<int> g;
        std::map<int, int> degrees;
        int n1, n2;

        for (int i = 0; i != e; ++i) {


            std::cin >> n1 >> n2;

            g.connect(n1, n2);
            g.connect(n2, n1);
            ++degrees[n1];
            ++degrees[n2];
        }

        if (eulerian_cycle(g, degrees)) {
            std::cout << "Possible" << std::endl;
        } else {
            std::cout << "Not Possible" << std::endl;
        }
    }

    return 0;
}

