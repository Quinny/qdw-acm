#include <iostream>
#include "directed_graph.h"

void bfs(directed_graph<int> g, int source) {
    std::set<int> visited;
    std::queue<int> q;

    q.push(source);
    visited.insert(source);
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        std::cout << top << std::endl;

        for (auto i: g[top]) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
}

int main() {
    int u, v;
    directed_graph<int> g;
    while (std::cin >> u >> v)
        g.connect(u, v);
    bfs(g, 7);
    return 0;
}
