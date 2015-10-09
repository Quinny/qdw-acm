#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include "weighted_graph.h"

template <typename T>
struct compare {
    bool operator()(std::pair<T, int> p1, std::pair<T, int> p2) {
        return p2.second < p1.second;
    }
};

template <typename T>
std::unordered_map<T, T> dijkstra(weighted_graph<T> g, T source) {
    std::priority_queue<
        std::pair<T, int>,
        std::vector<std::pair<T, int>>,
        compare<T>
    > q;
    std::unordered_map<T, std::size_t> dist;
    std::unordered_map<T, T> prev;

    dist.insert({source, 0});
    q.push({source, 0});

    for (T v : g.vertices) {
        if (v != source)
            dist.insert({v, 1000});
    }

    while (!q.empty()) {
        auto top = q.top();
        q.pop();

        for (auto neighb : g[top.first]) {
            std::size_t alt = dist[top.first] + neighb.second;
            if (alt < dist[neighb.first]) {
                dist[neighb.first] = alt;
                prev[neighb.first] = top.first;
                q.push(neighb);
            }
        }
    }

    return prev;
}

int main() {
    int dist;
    char u, v;
    weighted_graph<char> g;

    while (std::cin >> u >> v >> dist) {
        g.connect(u, v, dist);
    }

    std::unordered_map<char, char> prev = dijkstra(g, 'a');

    for (auto p : prev) {
        std::cout << p.second << "->" << p.first << std::endl;
    }

    return 0;
}

