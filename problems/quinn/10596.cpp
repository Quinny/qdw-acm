#include <iostream>
#include "../../graphs/directed_graph.h"
#include <set>

bool possible(directed_graph<int>& g, int cur,
        std::set<std::pair<int, int>> path, std::size_t edges) {
    if (cur == 0 && path.size() == edges)
        return true;

    for (auto i: g[cur]) {
        if (path.find({cur, i}) == path.end()) {
            auto tmp = path;
            tmp.insert({cur, i});
            auto check = possible(g, i, tmp, edges);
            if (check) return true;
        }
    }

    return false;
}

int main() {
    std::size_t nodes, edges;
    while (std::cin >> nodes >> edges) {
        directed_graph<int> g;
        for (int i = 0; i < edges; ++i) {
            int n1, n2;
            std::cin >> n1 >> n2;
            g.connect(n1, n2);
        }
        std::set<std::pair<int, int>> p;
        std::cout << possible(g, 0, p, edges) << std::endl;
    }
    return 0;
}
