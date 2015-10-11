#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "../../graphs/directed_graph.h"

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

