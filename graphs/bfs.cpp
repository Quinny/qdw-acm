#include <iostream>
#include <functional>
#include "directed_graph.h"

using callback = std::function<void(int)>;

void bfs(directed_graph<int> g, int source, callback cb) {
    std::set<int> visited;
    std::queue<int> q;

    q.push(source);
    visited.insert(source);
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        cb(top);

        for (auto i: g[top]) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
}

void print(int x) {
    std::cout << x << std::endl;
}

int main() {
    int u, v;
    directed_graph<int> g;
    while (std::cin >> u >> v)
        g.connect(u, v);
    bfs(g, 7, print);
    return 0;
}
